cmake_minimum_required( VERSION 3.10 )

project (PerfectNumbers
VERSION 0.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#For testing include catch2/3
find_package(Catch2 3 REQUIRED)


#add_library(someLibrary someLibrary.cpp someLibrary.h)


add_executable(PerfectNumbers main.cpp)

target_link_libraries(PerfectNumbers PRIVATE #someLibrary
						 Catch2::Catch2)
