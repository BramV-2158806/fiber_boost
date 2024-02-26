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

		TEST_METHOD(TestMergeSortThreadsHuge) {
			// includes 70 elements and duplicates
			std::vector<int> arr = { 83, 86, 77, 15, 93, 35, 86, 92, 49, 21,
												62, 27, 90, 59, 63, 26, 40, 26, 72, 36,
												11, 68, 67, 29, 82, 30, 62, 23, 67, 35,
												29, 2, 22, 58, 69, 67, 93, 56, 11, 42,
												29, 73, 21, 19, 84, 37, 98, 24, 15, 70,
												13, 26, 91, 80, 56, 73, 62, 70, 96, 81,
												5, 25, 84, 27, 36, 5, 46, 29, 13, 57,
												24, 95, 82, 45, 14, 67, 34, 64, 43, 50 };
			MergeSortThreads mergeSortThreads;
			std::vector<int> result = mergeSortThreads.MergeSort(arr);
			std::vector<int> expected = { 2, 5, 5, 11, 11, 13, 13, 14, 15, 15, 19, 21, 
											21, 22, 23, 24, 24, 25, 26, 26, 26, 27, 27, 
											29, 29, 29, 29, 30, 34, 35, 35, 36, 36, 37, 
											40, 42, 43, 45, 46, 49, 50, 56, 56, 57, 58, 
											59, 62, 62, 62, 63, 64, 67, 67, 67, 67, 68, 
											69, 70, 70, 72, 73, 73, 77, 80, 81, 82, 82, 
											83, 84, 84, 86, 86, 90, 91, 92, 93, 93, 95, 96, 98 };
			Assert::IsTrue(result == expected);
			Logger::WriteMessage("This is a message for the test explorere.");
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

		TEST_METHOD(TestMergeSortFibersHuge) {
			// includes 70 elements and duplicates
			std::vector<int> arr = { 83, 86, 77, 15, 93, 35, 86, 92, 49, 21,
												62, 27, 90, 59, 63, 26, 40, 26, 72, 36,
												11, 68, 67, 29, 82, 30, 62, 23, 67, 35,
												29, 2, 22, 58, 69, 67, 93, 56, 11, 42,
												29, 73, 21, 19, 84, 37, 98, 24, 15, 70,
												13, 26, 91, 80, 56, 73, 62, 70, 96, 81,
												5, 25, 84, 27, 36, 5, 46, 29, 13, 57,
												24, 95, 82, 45, 14, 67, 34, 64, 43, 50 };
			MergeSortFibers mergeSortFibers;
			std::vector<int> result = mergeSortFibers.MergeSort(arr);
			std::vector<int> expected = { 2, 5, 5, 11, 11, 13, 13, 14, 15, 15, 19, 21,
											21, 22, 23, 24, 24, 25, 26, 26, 26, 27, 27,
											29, 29, 29, 29, 30, 34, 35, 35, 36, 36, 37,
											40, 42, 43, 45, 46, 49, 50, 56, 56, 57, 58,
											59, 62, 62, 62, 63, 64, 67, 67, 67, 67, 68,
											69, 70, 70, 72, 73, 73, 77, 80, 81, 82, 82,
											83, 84, 84, 86, 86, 90, 91, 92, 93, 93, 95, 96, 98 };
			Assert::IsTrue(result == expected);
		}
	};
}
