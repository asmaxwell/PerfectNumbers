# Simple Perfect Number Tester and Generator
## Introduction
A simple library and example main file for testing and generating Perfect numbers. Perfect numbers are numbers whose factors (not including itself) sum to the number.
## Prerequisites 
In order to install this code you will need the following libraires installed:
* CMake (to compile)
* Catch2 (if you want to use the test features---CMake can get this for you)

## Install and compile
First download the code from Github however you prefer. Then compile using CMake. If you do this over the command line go to the directory build/default/ and run the following:
```cmake -S . -B build```

`cmake --build build`

This will also compile the tests, fi you don't want to compile these for the last command run:
`cmake --build build --target PerfectNumbers`

To run the tests in build/ directory run `ctest`

## Structure of code
In src/ we have the PerfectNumber library, in app/ there is the example main and in test/ are all the tests.