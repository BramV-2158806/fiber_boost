#include <vector>
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

		boost::fibers::fiber leftFiber([this, left]() {
			std::vector<int> resultLeft = MergeSort(left);
		});

		boost::fibers::fiber rightFiber([this, right]() {
			std::vector<int> resultRight = MergeSort(right);
		});

		leftFiber.join();
		rightFiber.join();

		return Merge(left, right);

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