// fibertest_boost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ab_fiber_example.cpp"


int main()
{
    AbFiberExample::RunExample();
    printf("Main thread is about to return\n"); // de main functie returned en dan word de join opgeroepen op alle fibers
    return 0;
}

