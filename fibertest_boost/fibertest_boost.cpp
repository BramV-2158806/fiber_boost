// fibertest_boost.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ab_fiber_example.cpp"
#include "MergeSortThreads.cpp"
#include "helpers.cpp"
#include "MergeSortFibers.cpp"


int main()
{
    // Big input array size 70
    std::vector<int> arr = { 83, 86, 77, 15, 93, 35, 86, 92, 49, 21,
                            62, 27, 90, 59, 63, 26, 40, 26, 72, 36,
                            11, 68, 67, 29, 82, 30, 62, 23, 67, 35,
                            29, 2, 22, 58, 69, 67, 93, 56, 11, 42,
                            29, 73, 21, 19, 84, 37, 98, 24, 15, 70,
                            13, 26, 91, 80, 56, 73, 62, 70, 96, 81,
                            5, 25, 84, 27, 36, 5, 46, 29, 13, 57,
                            24, 95, 82, 45, 14, 67, 34, 64, 43, 50 };

    std::cout << "THREADS: Given array: " << Helpers::VectorToString(arr) << std::endl;
    MergeSortThreads mergeSortThreads;
    std::vector<int> result = mergeSortThreads.MergeSort(arr);
    std::cout << "Sorted array: " << Helpers::VectorToString(result) << std::endl;

    std::cout << "FIBERS: Given array: " << Helpers::VectorToString(arr) << std::endl;
    MergeSortFibers mergeSortFibers;
    result = mergeSortFibers.MergeSort(arr);
    std::cout << "Sorted array: " << Helpers::VectorToString(result) << std::endl;


    printf("Main thread is about to return\n"); // de main functie returned en dan word de join opgeroepen op alle fibers
    return 0;
}

