// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000
// It's guaranteed that you can reach nums[n - 1].

#include <stdio.h>
#include <stdlib.h>

int jump(int* nums, int numsSize) {
    if (numsSize == 1) return 0;

    int jumps = 0;
    int range = 0;
    int far = 0;

    for (int i = 0; i < numsSize; i++) {
        int d = i + nums[i];
        if (d >= numsSize - 1) return jumps + 1;
        if (d > far) far = d;
        if (i == range) {
            range = far;
            jumps++;
        }
    }

    return jumps;
}

int main() {
    // g.
    int nums[] = {2,3,1,1,4};
    int numsSize = 5;

    int answer = jump(nums, numsSize);
    printf("answer: %d\n", answer);

    return 0;
}

// Runtime: 0ms 100.00%
// Memory: 9.05MB 38.85%