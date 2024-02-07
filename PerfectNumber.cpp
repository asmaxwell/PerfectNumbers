#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

#include "PerfectNumber.h"


PerfectNumber::PerfectNumber()
{

}

PerfectNumber::~PerfectNumber()
{

}

std::vector<size_t> PerfectNumber::findFactors(std::size_t n, bool bSort){
    /*
    * Find all factor of number n
    */
   // 1 and n are always factors but have to exclude n for perfect numbers, now divide by 
   std::vector<std::size_t> factors ={1};
   
   // do case divide by 2 manually then exclude even number if it doesn't
   bool b_even = false;
   auto div_result = std::div(n, 2);
   size_t quot = div_result.quot, rem = div_result.rem;
   if(rem==0){
    b_even = true;
    factors.push_back(2);
    factors.push_back(quot);
   }

   for(auto i = 3; i!=n/2; i+=2){
      auto div_result = std::div(n, i); //does the division and modulo in one go
      size_t quot = div_result.quot, rem = div_result.rem;
      
      if(i>quot) break; // could stop at the integer below sqrt(n) but for it is faster to add this break clause
      if(rem==0){
        factors.push_back(i);
        factors.push_back(quot);
      }
      if(b_even){ //if n is even also test even numbers otherwise skip them all
        auto div_result = std::div(n, i+1); //does the division and modulo in one go
        size_t quot = div_result.quot, rem = div_result.rem;
        
        if(i+1>quot) break; // could stop at the integer below sqrt(n) but for it is faster to add this break clause
        if(rem==0){
            factors.push_back(i+1);
            factors.push_back(quot);
        }
      }
   }
   if(bSort)std::sort(factors.begin(), factors.end());
   return factors;
}

bool PerfectNumber::isPerfect(std::size_t n){
    /*
    * Test is number n is a perfect number
    */
   std::vector<size_t> factors = findFactors(n);
//    printFactors(factors);
   std::size_t n_sum = std::accumulate(factors.begin(), factors.end(), 0);
   return n_sum == n;
}

std::vector<size_t> PerfectNumber::findNPerfects(const std::size_t N, const std::size_t max_iterations, const bool bPrintProgress){
    /*
    * find the fist N Perfect numbers. Very intensive even for quite small N!
    */
    std::vector<size_t> perfect_numbers;
    for(size_t i = 2; i!=max_iterations; ++i){
        if(bPrintProgress && i%50000==0) std::cout<<"iteration "<<i<<" of a maximum of "<<max_iterations<<"\n";     

        if(isPerfect(i)){
            std::cout<<"found perfect number: "<<i<<"\n";
            perfect_numbers.push_back(i);
            if(perfect_numbers.size()==N) break;
        }
    }
   if(perfect_numbers.size()<N) std::cerr<<"Warning not all Perfect numbers were found before max_iterations was reached!\n";
   return perfect_numbers;
}

void PerfectNumber::printFactors(const std::vector<size_t>& factors) const{
    std::cout<<"factors = ";
    for(const auto& factor : factors){
        std::cout<<factor<<" ";
    }
    std::cout<<"\n";
}

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
