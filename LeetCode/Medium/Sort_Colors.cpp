// Given an array nums with n objects colored red, white, or blue,
// sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int redIdx = 0;
		int blueIdx = nums.size() - 1;
		int currentIdx = 0;

		while (currentIdx < nums.size()) {
			int color = nums[currentIdx];

			if (color == 0 && currentIdx > redIdx) {
				swap(nums[currentIdx], nums[redIdx++]);
				if (nums[currentIdx] != 1) continue;
			} else if (color == 2 && currentIdx < blueIdx) {
				swap(nums[currentIdx], nums[blueIdx--]);
				if (nums[currentIdx] != 1) continue;
			}

			currentIdx++;
		}
	}
};

int main() {
	vector<int> nums = {1,2,0};

	Solution s;
	s.sortColors(nums);

	printf("answer: ");
	for (int i = 0; i < nums.size(); ++i) {
		printf("%d ", nums[i]);
	}
	printf("\n");

	return 0;
}

// Runtime: 0ms 100.00%
// Memory: 11.64MB 47.28%