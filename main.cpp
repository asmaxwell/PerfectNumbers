#include <iostream>
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>
#include <chrono>

#include "PerfectNumber.h"

/*
 * Created by Andrew S Maxwell 06/02/2024
 *
 * Generate and test perfect numbers
 * That is numbers that are equal to the sum of their factors 
 */

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

int main(int argc, char **argv) {

	// --- Testing suite --- //
	int result = 0;
	//uncomment below to run all unit tests
	// result = Catch::Session().run( argc, argv );
	// --- Testing End --- //

	PerfectNumber PN;
	auto t1 = high_resolution_clock::now();
	auto perfect_numbers = PN.findNPerfects(5, 50000000, false);
	auto t2 = high_resolution_clock::now();

	/* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;

	std::cout<<"Execution took "<<ms_double.count()<<" ms\n";
	


	return result;
}

TEST_CASE( "1: All test cases reside in other .cpp files (empty)", "[multi-file:1]" ) {
}
