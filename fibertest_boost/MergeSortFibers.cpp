#include <vector>
#include <future>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <boost/fiber/all.hpp>

class MergeSortFibers {
public:
	std::vector<int> MergeSort(std::vector<int> arr) {
		if (arr.size() <= 1) {
			return arr;
		}

		int middle = arr.size() / 2;
		std::vector<int> left(arr.begin(), arr.begin() + middle);
		std::vector<int> right(arr.begin() + middle, arr.end());

		std::promise<std::vector<int>> leftPromise;
		std::future<std::vector<int>> leftFuture = leftPromise.get_future();
		std::promise<std::vector<int>> rightPromise;
		std::future<std::vector<int>> rightFuture = rightPromise.get_future();

		boost::fibers::fiber leftFiber([this, &leftPromise, left]() {
			std::vector<int> resultLeft = MergeSort(left);
			leftPromise.set_value(std::move(resultLeft));
		});

		boost::fibers::fiber rightFiber([this, &rightPromise, right]() {
			std::vector<int> resultRight = MergeSort(right);
			rightPromise.set_value(std::move(resultRight));
		});

		leftFiber.join();
		rightFiber.join();

		std::vector<int> resultLeft = leftFuture.get();
		std::vector<int> resultRight = rightFuture.get();

		return Merge(resultLeft, resultRight);

	}

private:


	// Merge the two arrays: left and right
	std::vector<int> Merge(std::vector<int> left, std::vector<int> right) {
		std::vector<int> result;
		int leftIndex = 0;
		int rightIndex = 0;

		while (leftIndex < left.size() && rightIndex < right.size()) {
			if (left[leftIndex] < right[rightIndex]) {
				result.push_back(left[leftIndex]);
				leftIndex++;
			}
			else {
				result.push_back(right[rightIndex]);
				rightIndex++;
			}
		}

		while (leftIndex < left.size()) {
			result.push_back(left[leftIndex]);
			leftIndex++;
		}

		while (rightIndex < right.size()) {
			result.push_back(right[rightIndex]);
			rightIndex++;
		}

		return result;
	}
};