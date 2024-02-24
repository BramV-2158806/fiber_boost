// fibertest_boost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ab_fiber_example.cpp"
#include "MergeSortThreads.cpp"
#include "helpers.cpp"


int main()
{
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    std::cout << "Given array: " << Helpers::VectorToString(arr) << std::endl;
    MergeSortThreads mergeSortThreads;
    std::vector<int> result = mergeSortThreads.MergeSort(arr);
    std::cout << "Sorted array: " << Helpers::VectorToString(result) << std::endl;

    printf("Main thread is about to return\n"); // de main functie returned en dan word de join opgeroepen op alle fibers
    return 0;
}

