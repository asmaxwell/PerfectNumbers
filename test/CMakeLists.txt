#can set catch2 to download for testing
FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.2)
FetchContent_MakeAvailable(catch)


#find_package(Catch2 3 REQUIRED) #if fetching catch2 this is not required
file(GLOB TEST_SOURCES "*.cpp")

add_executable(test_PerfectNumbers ${TEST_SOURCES})

target_link_libraries(test_PerfectNumbers PRIVATE PerfectNumber Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
#include(CTest) #include already in root CMakeLists.txt
include(Catch)
catch_discover_tests(test_PerfectNumbers)
enable_testing()
add_test(NAME test_PerfectNumbers COMMAND test_PerfectNumbers) # Command can be a target