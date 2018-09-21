#include "pch.h"
#include <iostream>
/*
	Boost.DateTime can be used to process time data such as calendar dates and times.
	Boost.DateTime only supports calendar dates based on the Gregorian calendar,which in general is not a problem since this is the most widely used calendar.
	The Gregorian calendar was introduced by Pope Gregory XII in 1582.
	Boost.DateTime supports calendar dates for the years 1400 to 9999, which means that support goes 

	Location-independent Times£º
		boost::posix_time::ptime defines a location-independent time.

	Location-dependent Times:
		boost::local_time::local_date_time, which is stores time-zone related data 

	Formatted Input and Output :
		Boost::DateTime lets you display results in differnt formats. Calendar dates and times can be formatted using
			boost::date_time::date_facet 
			boost::date_time::time_facet 
*/

// Example 36.1. Creating a date with boost::gregorian::date 
#include <boost/date_time/gregorian/gregorian.hpp>

// Example 36.2. Getting a date from a clock or a string 
using namespace boost::gregorian;

// Example 36.3. Using boost::gregorian::date_duration 

// Example 36.4. Specialized durations 

// Example 36.5. Processing specialized durations 

// Example 36.6. Surprise when processing specialized durations

// Example 36.7. Using boost::gregorian::date_period 

// Example 36.8. Testing whether a period contains dates 

// Example 36.9. Iterating over dates 

// Example 36.10. Using boost::posix_time::ptime 
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::posix_time;

// Example 36.11. Creating a timepoint with a clock or a string 

// Example 36.12. Using boost::posix_time::time_duration 

// Example 36.13. Processing timepoints 

// Example 36.14. Processing time durations 

// Example 36.15. Using boost::posix_time::time_period 

// Example 36.16. Iterating over points in time 

// Example 36.17. Using boost::local_time::local_date_time 
#include <boost/date_time/local_time/local_time.hpp>

using namespace boost::local_time;

// Example 36.18. Location-dependent points in time and different time zones

// Example 36.19. Using boost::local_time::local_time_period 

// Example 36.20. A user-defined format for a date 

// Example 36.21. Changing names of weekdays and months 
#include <string>
#include <vector>
#include <locale>

#ifdef CHYI

int main(int argc, char* argv[])
{
	// Example 36.1. Creating a date with boost::gregorian::date 
	boost::gregorian::date d1{ 2018, 9, 21 };
	// return the respective parts of a date.
	std::cout << d1.year() << '\n';
	std::cout << d1.month() << '\n';
	std::cout << d1.day() << '\n';

	std::cout << d1.day_of_week() << '\n';
	std::cout << d1.end_of_month() << '\n';

	// Example 36.2. Getting a date from a clock or a string 
	date d2 = day_clock::universal_day(); // day_clock() return the current date, universal_day() return a UTC date.which is independent of time zones and daylight saving
	std::cout << d2.year() << '\n';
	std::cout << d2.month() << '\n';
	std::cout << d2.day() << '\n';

	d2 = date_from_iso_string("19930201");
	std::cout << d2.year() << '\n';
	std::cout << d2.month() << '\n';
	std::cout << d2.day() << '\n';

	// Example 36.3. Using boost::gregorian::date_duration 
	date d31{ 2018,9,18 };
	date d32{ 2018,9,21 };
	// Because boost::gregorian::date overloads operators, two points in time can be subtracted 
	date_duration dd3 = d32 - d31;
	std::cout << dd3.days() << '\n';

	// Example 36.4. Specialized durations 
	date_duration dd4{ 4 };
	std::cout << dd4.days() << '\n';
	weeks ws4{ 4 };
	std::cout << ws4.days() << '\n';
	months ms4{ 4 };
	std::cout << ms4.number_of_months() << '\n';
	years ys4{ 4 };
	std::cout << ys4.number_of_years() << '\n';

	// Example 36.5. Processing specialized durations 
	date d5{ 2018, 9, 21 };
	months ms5{ 1 };
	date d52 = d5 + ms5; // adds one month to the given date of January
	std::cout << d52 << '\n';
	date d53 = d52 - ms5;
	std::cout << d53 << '\n';

	// Example 36.6. Surprise when processing specialized durations
	date d6{ 2014, 1, 30 }; // which simply jumps forwards and backwards by a specified number of days and does not give special consideration to the first and last day of the month.
	months ms6{ 1 };
	date d62 = d6 + ms6;
	std::cout << d62 << '\n';
	date d63 = d62 - ms6;
	std::cout << d63 << '\n';

	// Example 36.7. Using boost::gregorian::date_period 
	date d71{ 2014, 1,1 };
	date d72{ 2014, 2, 28 };
	date_period dp7{ d71, d72 }; // Please note that the day before the end date is actually the last day of the period.
	date_duration dd7 = dp7.length();
	std::cout << dd7.days() << '\n';

	// Example 36.8. Testing whether a period contains dates 
	date d81{ 2014, 1,1 };
	date d82{ 2014, 2, 28 };
	date_period dp8{ d81, d82 };
	std::cout.setf(std::ios::boolalpha);
	// checks whether a specific a specific date is within a period by calling contains
	std::cout << dp8.contains(d81) << '\n';
	std::cout << dp8.contains(d82) << '\n';

	// Example 36.9. Iterating over dates 
	date d9{ 2014, 5, 12 };
	day_iterator it9{ d9 }; // jump forward or backward by a day from a specific date.
	std::cout << *++it9 << '\n';
	std::cout << boost::date_time::next_weekday(*it9, // which returns the date of the next weekday based on a given date.
		greg_weekday(boost::date_time::Friday)) << '\n';

	// Example 36.10. Using boost::posix_time::ptime 
	ptime pt10{ date{2014, 5, 12}, time_duration{12, 0, 0} };
	date d10 = pt10.date(); // query date 
	std::cout << d10 << '\n';
	time_duration td10 = pt10.time_of_day(); // query time 
	std::cout << td10 << '\n';

	// Example 36.11. Creating a timepoint with a clock or a string 
	ptime pt11 = second_clock::universal_time(); // second_clock returns the current time. universal_time() return the UTC time.
	std::cout << pt11.date() << '\n';
	std::cout << pt11.time_of_day() << '\n';

	pt11 = from_iso_string("20180921T134400"); // converts a time stored in a string formatted using the ISO 8601 standard into an object of type.
	std::cout << pt11.date() << '\n';
	std::cout << pt11.time_of_day() << '\n';

	// Example 36.12. Using boost::posix_time::time_duration 
	time_duration td12{ 16, 30, 0 };
	std::cout << td12.hours() << '\n';
	std::cout << td12.minutes() << '\n';
	std::cout << td12.seconds() << '\n';
	std::cout << td12.total_seconds() << '\n'; // which returns the total number of seconds 

	// Example 36.13. Processing timepoints 
	ptime pt131{ date{2014, 5, 12}, time_duration{12, 0, 0} };
	ptime pt132{ date{2014, 5, 12}, time_duration{18, 30,0} };
	time_duration td = pt132 - pt131; // specifies the duration between the two times.
	std::cout << td.hours() << '\n';
	std::cout << td.minutes() << '\n';
	std::cout << td.seconds() << '\n';

	// Example 36.14. Processing time durations 
	ptime pt141{ date{2014, 5, 12}, time_duration{12, 0, 0} };
	time_duration td14{ 6, 30, 0 };
	ptime pt142 = pt141 + td14;
	std::cout << pt142.time_of_day() << '\n';

	// Example 36.15. Using boost::posix_time::time_period 
	ptime pt151{ date{2014, 5, 12}, time_duration{12, 0, 0} };
	ptime pt152{ date{2014, 5, 12}, time_duration{18, 30, 0} };
	time_period tp15{ pt151, pt152 };
	std::cout.setf(std::ios::boolalpha);
	std::cout << tp15.contains(pt151) << '\n';
	std::cout << tp15.contains(pt152) << '\n';

	// Example 36.16. Iterating over points in time 
	ptime pt16{ date{2014, 5, 12}, time_duration{12, 0, 0} };
	time_iterator it16{ pt16, time_duration{6, 30, 0} };
	std::cout << *++it16 << '\n'; // uses the iterator it to jump forward 6.5 hours from the time pt
	std::cout << *++it16 << '\n';

	// Example 36.17. Using boost::local_time::local_date_time 
	time_zone_ptr tz17{ new posix_time_zone{"CET+1"} }; // CET is the abbreviation for Central Curopean Time.ÖÐÅ·Ê±¼ä
	ptime pt17{ date{2014, 5, 12}, time_duration{12, 0,0} };

	local_date_time dt17{ pt17, tz17 };
	std::cout << dt17.utc_time() << '\n';
	std::cout << dt17 << '\n';
	std::cout << dt17.local_time() << '\n';
	std::cout << dt17.zone_name() << '\n';

	// Example 36.18. Location-dependent points in time and different time zones
	time_zone_ptr tz18{ new posix_time_zone{"CET+8"} };
	ptime pt18{ date{2014, 5, 12}, time_duration{12, 0, 0} };
	local_date_time dt18{ pt18, tz18 };
	std::cout << dt18.local_time() << '\n';

	time_zone_ptr tz182{ new posix_time_zone{"EET+2"} };
	std::cout << dt18.local_time_in(tz182).local_time() << '\n';

	// Example 36.19. Using boost::local_time::local_time_period 
	time_zone_ptr tz19{ new posix_time_zone{"CET+0"} };
	ptime pt191{ date{2014, 12, 5}, time_duration{12, 0, 0} };
	local_date_time dt191{ pt191, tz19 };

	ptime pt192{ date{2014, 12, 5}, time_duration{18, 0, 0} };
	local_date_time dt192{ pt192, tz19 };

	local_time_period tp19{ dt191, dt192 };

	std::cout.setf(std::ios::boolalpha);
	std::cout << tp19.contains(dt191) << '\n';
	std::cout << tp19.contains(dt192) << '\n';

	// Example 36.20. A user-defined format for a date 
	date d20{ 2014, 5, 12 };
	date_facet *df20 = new date_facet{ "%A, %d %B %Y" };
	std::cout.imbue(std::locale{ std::cout.getloc(), df20 });
	std::cout << d20 << '\n';

	// Example 36.21. Changing names of weekdays and months 
	std::locale::global(std::locale{ "German" });
	std::string months21[12]{ "Januar", "Februar", "M\xe4rz", "April",
   "Mai", "Juni", "Juli", "August", "September", "Oktober",
   "November", "Dezember" };
	std::string weekdays[7]{ "Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag" };
	date d21{ 2014, 5, 12 };
	date_facet *df21 = new date_facet{ "%A, %d. %B %Y" };
	df21->long_month_names(std::vector<std::string>{months21, months21 + 12});
	df21->long_weekday_names(std::vector<std::string>{weekdays, weekdays + 7});
	std::cout.imbue(std::locale{ std::cout.getloc(), df21 });
	std::cout << d21 << '\n';


	return 0;
}
#endif 