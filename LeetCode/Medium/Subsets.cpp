// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:

// Input: nums = [0]
// Output: [[],[0]] 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void r(vector<int>& nums, vector<int>& v, vector<vector<int>>& answer, int index) {
    for (int i = index; i < nums.size(); ++i) {
      v.push_back(nums[i]);
      answer.push_back(v);
      r(nums, v, answer, i + 1);
      v.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> answer;
    vector<int> v;
    answer.push_back(v);
    r(nums, v, answer, 0);
    return answer;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};

  Solution s;
  vector<vector<int>> answer = s.subsets(nums);
  cout << "answer: " << endl;
  for (int i = 0; i < answer.size(); ++i) {
    for (int j = 0; j < answer[i].size(); ++j) {
      cout << answer[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

// Runtime: 0ms 100.00%
// Memory: 9.88MB 80.56%