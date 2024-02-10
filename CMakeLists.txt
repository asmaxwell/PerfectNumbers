cmake_minimum_required( VERSION 3.10 )

project (PerfectNumbers
VERSION 0.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
#set some more flags!
set(CMAKE_CXX_FLAGS "-Wall -Wextra -fopenmp")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#support for folders in IDEs
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include(FetchContent)

# The compiled library code is here
add_subdirectory(src)
# Example main is here
add_subdirectory(app)




# Add Testing
include(CTest)
add_subdirectory(test)
