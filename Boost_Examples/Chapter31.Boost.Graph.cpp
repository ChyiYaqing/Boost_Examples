#include "pch.h"
/*
	Graphs consist of points and lines.

*/

// Example 31.1. A graph of type boost::adjacency_list with four vertices 
#include <boost/graph/adjacency_list.hpp>
#include <iostream>

// Example 31.2. Accessing vertices with boost::vertices()
#include <utility>
#include <algorithm>
#include <iterator>

#ifdef CHYI




int main(int argc, char* argv[])
{
	// Example 31.1. A graph of type boost::adjacency_list with four vertices 	
	boost::adjacency_list<> g1; // std::vector is the container 
	// In graph theory, a point is called vertex: ¶¥µã
	boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(g1);	// add points to the graph
	boost::adjacency_list<>::vertex_descriptor v2 = boost::add_vertex(g1);	// adds a point to a graph
	boost::adjacency_list<>::vertex_descriptor v3 = boost::add_vertex(g1);  // 
	boost::adjacency_list<>::vertex_descriptor v4 = boost::add_vertex(g1);  // 

	std::cout << v1 << ", " << v2 << ", " << v3 << ", " << v4 << '\n';

	// Example 31.2. Accessing vertices with boost::vertices()
	boost::adjacency_list<> g2;
	boost::add_vertex(g2);
	boost::add_vertex(g2);
	boost::add_vertex(g2);
	boost::add_vertex(g2);

	std::pair<boost::adjacency_list<>::vertex_iterator,
		boost::adjacency_list<>::vertex_iterator> vs2 = boost::vertices(g2);
	std::copy(vs2.first, vs2.second,
		std::ostream_iterator<boost::adjacency_list<>::vertex_descriptor>{
		std::cout, "\n"});

	return 0;
}
#endif // CHYI