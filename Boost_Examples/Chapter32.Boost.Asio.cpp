#include "pch.h"
/*
	I/O Services and I/O objects 
		I/O services abstract the operating system interfaces that process data asynchronously.
		I/O objects initiate asynchronous operations.

		I/O services look towards the operating system API
		I/O objects look towards tasks developers need to do.

		only one class for an I/O service object, several classes for I/O objects exist. Because I/O objects are task oriented.

	Scalability and Multithreading:
		Boost.Asio starts asynchronous operations. Functions which should be called after an operation has finished are now called within the corresponding handler.
		Remeber that asynchronous operations are usually used to access resources outside of a process.
		With Boost.Asio it is possible to benefit from the ability of external devices to execute operations concurrently.If threads are used, several functions can be executed concurrently on avalable CPU cores.
		Boost.Asio with threads improves the scalability because your program can take advantage of internal and external devices that can execute operations independently or in cooperation with each other.

		On Windows, boost::asio::io_service is usually based on IOCP, 
		On Linux, it is based on epoll() 
		Having serall I/O service objects means that several I/O completion ports will be used or epoll() will be called multiple times. Whether this better than using just one I/O completion port ot on 

	Network programming
		Even though Boost.Asio can process any kind of data asynchronously, it is mainly used for network programming.
		Network functions are a perfect use for asynchronous operations because the transmission of data over a network may take a long time,which means acknowledgment and errors
		may not be available as fast as the functions that send or receive data can execute.

	Coroutines: Ð­Í¬³ÌÐò

	Platform-specific I/O Objects:
		boost::asio::steady_timer and boost::asio::ip::tcp::socket are supported on all platforms.However, Boost.Asio also provides
		platform-specific I/O objects because some asyncronous operations are only available on certain platforms.


*/

// Example 32.1. Using boost::asio::steady_timer 
#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>  // wait for a time period to expire.
#include <chrono>
#include <iostream>
using namespace boost::asio; 

// Example 32.2. Two asynchronous operations with boost::asio::steady_timer 

// Example 32.3. Two threads for the I/O service object to execute handlers concurrently
#include <thread>

// Example 32.4. One thread for each of two I/O service objects to execute handlers concurrently 

// Example 32.5. A web client with boost::asio::ip::tcp::scoket 
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <array>
#include <string>

using namespace boost::asio::ip;

io_service ioservice5;
tcp::resolver resolv5{ ioservice5 };
tcp::socket tcp_socket{ ioservice5 };
std::array<char, 4096> bytes5;

// received data 
void read_handler5(const boost::system::error_code &ec,
	std::size_t bytes_transferred) { // The parameter bytes_transferred of type std::size_t contains the number of bytes that have been received.
	if (!ec) {
		std::cout.write(bytes5.data(), bytes_transferred);
		// This is required because you can't be sure that the entire homepage was downloaded and copied into bytes in a single asynchronous operation.
		tcp_socket.async_read_some(buffer(bytes5), read_handler5);
	}
}

// established connection
void connect_handler5(const boost::system::error_code &ec) {
	if (!ec) { // Again ec is checked first to find our whether a connection could be established 
		std::string r = "GET / HTTP/1.1\r\nHost: theboostcpplibraries.com\r\n\r\n";
		write(tcp_socket, buffer(r)); // tcp_socket is accessed to send a HTTP request and start receiving data.
		tcp_socket.async_read_some(buffer(bytes5), read_handler5); // The array bytes is used to store data received.
	}
}

// resolution name 
void resolve_handler5(const boost::system::error_code &ec,
	tcp::resolver::iterator it) { // which points to an endpoint resolved from the name
	if (!ec) {
		// Only then is the socket accessed to establish a connection.
		tcp_socket.async_connect(*it, connect_handler5);
	}
}

// Example 32.6. A time server with boost::asio::ip::tcp::acceptor 
#include <ctime>
#include <iomanip>


io_service ioservice6; // time server 
// tcp::endpoint is used to tell tcp_acceptor to accept incoming connections of 
// version 4 of the internet protocol on port 2018
tcp::endpoint tcp_endpoint6{ tcp::v4(), 2018 };
// accept an incoming connection from another program
tcp::acceptor tcp_acceptor6{ ioservice6, tcp_endpoint6 };
tcp::socket tcp_socket6{ ioservice6 };
std::string data6{"Stay hungry stay foolish"};
//char str6[26];

void write_handler6(const boost::system::error_code &ec,
	std::size_t bytes_transferred) {
	if (!ec) {
		// which says the program is done sending data through the socket.
		tcp_socket6.shutdown(tcp::socket::shutdown_send);
	}
}

void accept_handler6(const boost::system::error_code &ec) {
	if (!ec) {
		std::time_t now = std::time(nullptr);
		//data6 = std::ctime(&now);
		// ctime_s(str6, sizeof str6, &now);

		// After the data has been sent, write_handler() is called.
		async_write(tcp_socket6, buffer(data6), write_handler6); // the current time is sent with 
	}
}

// Example 32.7. Coroutines with Boost.Asio 
#include <boost/asio/spawn.hpp>
#include <list>

io_service ioservice7;
tcp::endpoint tcp_endpoint7{ tcp::v4(), 2019 };
tcp::acceptor tcp_acceptor7{ ioservice7, tcp_endpoint7 };
std::list<tcp::socket> tcp_sockets7;

// coroutines , you can pass an object of type boost::asio::yield_context to asynchonous functions.
// When these asynchronous operations complete, the program continues where it left off.
void do_write7(tcp::socket &tcp_socket, yield_context yield) {
	std::time_t now = std::time(nullptr);
	struct tm time_info;
	localtime_s(&time_info, &now);
	char timebuf[26];
	errno_t err;
	err = asctime_s(timebuf, 26, &time_info);
	async_write(tcp_socket, buffer(timebuf), yield);
	tcp_socket.shutdown(tcp::socket::shutdown_send);
}

void do_accept7(yield_context yield) {
	for (int i = 0; i < 2; ++i) {
		tcp_sockets7.emplace_back(ioservice7);
		tcp_acceptor7.async_accept(tcp_sockets7.back(), yield);
		// use coroutines with Boost.Asio is boost::asio::spwan()
		spawn(ioservice7, [](yield_context yield)
		{do_write7(tcp_sockets7.back(), yield); });
	}
}

// 

#ifdef CHYI 

int main(int argc, char* argv[])
{
	// Example 32.1. Using boost::asio::steady_timer 
	io_service ioservice1; // create an I/O service object 

	// all I/O objects expect an I/O service object as a first parameter in their constructor.
	steady_timer timer1{ ioservice1, std::chrono::seconds{3} };

	// async_wait() return immediately., operating system to notify a program when a time period expires.
	timer1.async_wait([](const boost::system::error_code &ec) // wait() blocking member function 
		{std::cout << "3 sec\n"; }); // a lambda function is passed as a handler 

	ioservice1.run(); // call to run() on the I/O service object.

	// Example 32.2. Two asynchronous operations with boost::asio::steady_timer 
	io_service ioservice2;

	steady_timer timer21{ ioservice2, std::chrono::seconds{3} };
	timer21.async_wait([](const boost::system::error_code &ec)
		{std::cout << "3 sec\n"; });

	steady_timer timer22{ ioservice2, std::chrono::seconds{4} };
	timer22.async_wait([](const boost::system::error_code &ec)
	{std::cout << "4 sec\n"; });

	ioservice2.run(); // It might comes as a suprise that asynchronous operations require a call to a blocking function, However, this is not a problem because the program has to be prevent from exiting.

	// Example 32.3. Two threads for the I/O service object to execute handlers concurrently
	io_service ioservice3;

	steady_timer timer31{ ioservice3, std::chrono::seconds{3} };
	timer31.async_wait([](const boost::system::error_code &ec)
		{std::cout << "thread1 : 3 sec\n";  });
	steady_timer timer32{ ioservice3, std::chrono::seconds{3} };
	timer32.async_wait([](const boost::system::error_code &ec) // both lambda functions can be executed concurrently
		{std::cout << "thread2 : 3 sec\n"; });
	// This makes it possible for the I/O service object to use both threads to execute handlers when asynchronous operations complete.
	// Both handlers, which may run in two threads concurrently, share the global resource std::cout.
	std::thread thread31{ [&ioservice3]() { ioservice3.run(); } };
	std::thread thread32{ [&ioservice3]() { ioservice3.run(); } };

	thread31.join();
	thread32.join();

	// Example 32.4. One thread for each of two I/O service objects to execute handlers concurrently 
	io_service ioservice41;
	io_service ioservice42;

	steady_timer timer41{ ioservice41, std::chrono::seconds{3} };
	timer41.async_wait([](const boost::system::error_code &ec)
		{std::cout << "ioservice 41: 3 sec\n"; });
	steady_timer timer42{ ioservice42, std::chrono::seconds{3} };
	timer42.async_wait([](const boost::system::error_code &ec)
		{std::cout << "ioservice 42: 3 sec\n"; });
	// However, instead of providing several threads to one I/O service object, you could also create multiple I/O service objects.
	std::thread thread41{ [&ioservice41]() {ioservice41.run(); } };
	std::thread thread42{ [&ioservice42]() {ioservice42.run();  } };

	thread41.join();
	thread42.join();

	// Example 32.5. A web client with boost::asio::ip::tcp::scoket  
	tcp::resolver::query q5{ "theboostcpplibraries.com", "80" }; // instantiated to create an object q, q represents a query for the name resolver.
	resolv5.async_resolve(q5, resolve_handler5); // an asynchronous operation is started to resolve the name,
	ioservice5.run(); // run() is called on the I/O service object to pass control to the operating system

	// Example 32.6. A time server with boost::asio::ip::tcp::acceptor 
	tcp_acceptor6.listen(); // to make the acceptor start listening.
	tcp_acceptor6.async_accept(tcp_socket6, accept_handler6); // A socket has to be passed as a first parameter to async_accept(), which will be used to send and receive data on a new connection.
	ioservice6.run();

	// Example 32.7. Coroutines with Boost.Asio 
	tcp_acceptor7.listen();
	spawn(ioservice7, do_accept7);
	ioservice7.run();

	return 0;
}
#endif 