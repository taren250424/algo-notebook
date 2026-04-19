// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Example 1:

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 200

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> memo;
  int m;
  int n;

  int dp(vector<vector<int>>& grid, int r, int c) {
    if (m < r + 1 || n < c + 1) return 80000;
    if (m == r + 1 && n == c + 1) return grid[r][c];
    if (memo[r * n + c] != -1) return memo[r * n + c];
    return memo[r * n + c] = grid[r][c] + min(dp(grid, r + 1, c), dp(grid, r, c + 1));
  }

  int minPathSum(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    memo = vector<int>(m * n, -1);
    return dp(grid, 0, 0);
  }
};

int main() {
  vector<vector<int>> grid = {
    {1,2,3},
    {4,5,6}
  };

  Solution s;
  int answer = s.minPathSum(grid);
  cout << "answer: " << answer << endl;

  return 0;
}

// Runtime: 0ms 100.00%
// Memory: 16.10MB 68.03%