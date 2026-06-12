// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
 
// Example 1:

// Input: word1 = "horse", word2 = "ros"
// Output: 3

// Explanation: 
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

// Example 2:

// Input: word1 = "intention", word2 = "execution"
// Output: 5

// Explanation: 
// intention -> inention (remove 't')
// inention -> enention (replace 'i' with 'e')
// enention -> exention (replace 'n' with 'x')
// exention -> exection (replace 'n' with 'c')
// exection -> execution (insert 'u')
 
// Constraints:

// 0 <= word1.length, word2.length <= 500
// word1 and word2 consist of lowercase English letters.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length();
		int n = word2.length();

		vector<int> pre(n + 1, 0);
		vector<int> cur(n + 1, 0);

		for (int i = 0; i <= n; i++) {
			pre[i] = i;
		}

		for (int i = 1; i <= m; i++) {
			cur[0] = i;

			for (int j = 1; j <= n; j++)  {
				if (word1[i - 1] == word2[j - 1]) {
					cur[j] = pre[j - 1];
				} else {
					int ins = cur[j - 1];
					int rep = pre[j - 1];
					int del = pre[j];
					cur[j] = min({ins, rep, del}) + 1;
				}
			}

			pre = cur;
		}

		return pre[n];
	}
};

int main() {
	string word1 = "horse";
	string word2 = "ros";

	Solution sol;
	int answer = sol.minDistance(word1, word2);
	printf("answer: %d\n", answer);

	return 0;
}

// Runtime: 3ms 91.70%
// Memory: 10.52MB 90.87%