#include <iostream>
#include <catch2/catch_session.hpp>
#include <catch2/catch_test_macros.hpp>

/*
 * Created by Andrew S Maxwell 06/02/2024
 *
 * Generate and test perfect numbers
 * That is numbers that are equal to the sum of their factors 
 */

int main(int argc, char **argv) {

	// --- Testing suite --- //
	int result = 0;
	//uncomment below to run all unit tests
	result = Catch::Session().run( argc, argv );
	// --- Testing End --- //

	


	return result;
}

TEST_CASE( "1: All test cases reside in other .cpp files (empty)", "[multi-file:1]" ) {
}
