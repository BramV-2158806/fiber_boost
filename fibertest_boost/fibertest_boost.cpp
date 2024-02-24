// fibertest_boost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <boost/fiber/all.hpp>
using namespace std;

void print_a()
{
    cout << "a";
    boost::this_fiber::yield();
}

void print_b()
{
    cout << "b";
    boost::this_fiber::yield();
}


int main()
{
    int i = 0;
    boost::fibers::fiber([&]() {
        do {
            print_a();
            i++;
        } while (i < 20);
        }).detach();

    boost::fibers::fiber([&]() {
        do {
            i++;
            print_b();
        } while (i < 20);
        }).detach();

        printf("Main thread is about to return\n"); // de main functie returned en dan word de join opgeroepen op alle fibers
        return 0;
}

