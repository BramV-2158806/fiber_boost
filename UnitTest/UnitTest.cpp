#include "pch.h"
#include "CppUnitTest.h"
#include "../fibertest_boost/ab_fiber_example.cpp"
#include "../fibertest_boost/MergeSortThreads.cpp"
#include "../fibertest_boost/helpers.cpp"
#include "../fibertest_boost/MergeSortFibers.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMergeSortThreads1)
		{
			std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
			MergeSortThreads mergeSortThreads;
			std::vector<int> result = mergeSortThreads.MergeSort(arr);
			std::vector<int> expected = { 5, 6, 7, 11, 12, 13 };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestMergeSortThreads2)
		{
			std::vector<int> arr = { 12, 11, 13, 5, 6, 7, 1, 2, 3, 4, 8, 9, 10 };
			MergeSortThreads mergeSortThreads;
			std::vector<int> result = mergeSortThreads.MergeSort(arr);
			std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
			Assert::IsTrue(result == expected);
		}
			
		TEST_METHOD(TestMergeSortThreadsReverse)
		{
			std::vector<int> arr = { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			MergeSortThreads mergeSortThreads;
			std::vector<int> result = mergeSortThreads.MergeSort(arr);
			std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestMergeSortThreadsEmpty)
		{
			std::vector<int> arr = {};
			MergeSortThreads mergeSortThreads;
			std::vector<int> result = mergeSortThreads.MergeSort(arr);
			std::vector<int> expected = {};
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestMergeSortThreadsSingle)
		{
			std::vector<int> arr = { 1 };
			MergeSortThreads mergeSortThreads;
			std::vector<int> result = mergeSortThreads.MergeSort(arr);
			std::vector<int> expected = { 1 };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestMergeSortFibers1)
		{
			std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
			MergeSortFibers mergeSortFibers;
			std::vector<int> result = mergeSortFibers.MergeSort(arr);
			std::vector<int> expected = { 5, 6, 7, 11, 12, 13 };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestMergeSortFibers2)
		{
			std::vector<int> arr = { 12, 11, 13, 5, 6, 7, 1, 2, 3, 4, 8, 9, 10 };
			MergeSortFibers mergeSortFibers;
			std::vector<int> result = mergeSortFibers.MergeSort(arr);
			std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestMergeSortFibersReverse)
		{
			std::vector<int> arr = { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
			MergeSortFibers mergeSortFibers;
			std::vector<int> result = mergeSortFibers.MergeSort(arr);
			std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestMergeSortFibersEmpty)
		{
			std::vector<int> arr = {};
			MergeSortFibers mergeSortFibers;
			std::vector<int> result = mergeSortFibers.MergeSort(arr);
			std::vector<int> expected = {};
			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(TestMergeSortFibersSingle)
		{
			std::vector<int> arr = { 1 };
			MergeSortFibers mergeSortFibers;
			std::vector<int> result = mergeSortFibers.MergeSort(arr);
			std::vector<int> expected = { 1 };
			Assert::IsTrue(result == expected);
		}
	};
}
