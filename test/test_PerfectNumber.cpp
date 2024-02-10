#include <iostream>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>

#include "../src/PerfectNumber.h"

/// --- Testing Suite --- ///
TEST_CASE( "Testing PerfectNumber Methods" ) {
    std::cout<<"testing!\n";
    PerfectNumber PN;
    SECTION("test findFactors"){
        auto factors10 = PN.findFactors(10, true);
        //test length first to prevent other test giving seg fault
        REQUIRE(factors10.size() == 3);       
        REQUIRE(factors10[0] == 1);
        REQUIRE(factors10[1] == 2);
        REQUIRE(factors10[2] == 5);
        //REQUIRE(factors10[3] == 10); case excluded

        auto factors17 = PN.findFactors(17);
        REQUIRE(factors17.size() == 1);
        REQUIRE(factors17[0] == 1);
        //REQUIRE(factors17[1] == 17); case excluded
    }

    SECTION("test isPerfect"){
        //Test first few perfect numbers
        REQUIRE(PN.isPerfect(6));
        REQUIRE(PN.isPerfect(28));
        REQUIRE(PN.isPerfect(496));
        REQUIRE(PN.isPerfect(8128));
        REQUIRE(PN.isPerfect(33550336));
        //Test some non-perfect numbers
        REQUIRE(!PN.isPerfect(8));
        REQUIRE(!PN.isPerfect(10));
        REQUIRE(!PN.isPerfect(17));
        REQUIRE(!PN.isPerfect(100));
        REQUIRE(!PN.isPerfect(1000));

    }
    SECTION("test findNPerfects"){
        auto perfect_numbers = PN.findNPerfects(5, 100000, true);
        REQUIRE(perfect_numbers.size() == 4);
        REQUIRE(perfect_numbers[0] == 6);
        REQUIRE(perfect_numbers[1] == 28);
        REQUIRE(perfect_numbers[2] == 496);
        REQUIRE(perfect_numbers[3] == 8128);
        //REQUIRE(perfect_numbers[4] == 33550336);
    }

}
