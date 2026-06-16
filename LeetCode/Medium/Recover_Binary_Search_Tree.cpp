// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 // Example 1:

// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.

// Example 2:

// Input: root = [3,1,4,null,null,2]
// Output: [2,1,4,null,null,3]
// Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

// Constraints:

// The number of nodes in the tree is in the range [2, 1000].
// -231 <= Node.val <= 231 - 1

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int NULL_NUM = 999;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  void inorder_change(TreeNode* node, vector<int>& v) {
    if (!node) return;
    inorder_change(node->left, v);
    node->val = v.back();
    v.pop_back();
    inorder_change(node->right, v);
  }

  void inorder_collect(TreeNode* node, vector<int>& v) {
    if (!node) return;
    inorder_collect(node->left, v);
    v.push_back(node->val);
    inorder_collect(node->right, v);
  }

  void recoverTree(TreeNode* root) {
    vector<int> v;
    inorder_collect(root, v);
    sort(v.begin(), v.end(), greater<int>());
    inorder_change(root, v);
  }
};

int main() {
  vector<int> arr = { 1, 3, NULL_NUM, NULL_NUM, 2 };
  TreeNode* root = (arr.size() > 0 && arr[0] != NULL_NUM) ? new TreeNode(arr[0]) : nullptr;

  deque<TreeNode*> dq;
  if (root) dq.push_back(root);
  
  int i = 1;
  while (!dq.empty() && i < arr.size()) {
    TreeNode* node = dq.front();
    dq.pop_front();

    if (i < arr.size() && (arr[i] != NULL_NUM)) {
      node->left = new TreeNode(arr[i]);
      dq.push_back(node->left);
    } 
    ++i;

    if (i < arr.size() && (arr[i] != NULL_NUM)) {
      node->right = new TreeNode(arr[i]);
      dq.push_back(node->right);
    } 
    ++i;
  }

  Solution sol;
  sol.recoverTree(root);

  cout << "answer: ";
  if (root) {
    dq.clear();
    cout << root->val << " ";
    dq.push_back(root);
    while (!dq.empty()) {
      TreeNode* node = dq.front();
      dq.pop_front();
  
      if (node->left) {
        cout << node->left->val << " ";
        dq.push_back(node->left);
      } 
  
      if (node->right) {
        cout << node->right->val << " ";
        dq.push_back(node->right);
      } 
    }
  }
  cout << endl;

  dq.clear();
  if (root) dq.push_back(root);
  int curr = 0;
  while (curr < (int)dq.size()) {
    TreeNode* node = dq[curr++];
    if (node->left) dq.push_back(node->left);
    if (node->right) dq.push_back(node->right);
  }

  while (!dq.empty()) {
    TreeNode* node = dq.back();
    dq.pop_back();
    delete node;
  }

  return 0;
}

// Runtime: 0ms 100.00%
// Memory: 61.16MB 13.79%