#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        TreeNode *root = new TreeNode(nums[(nums.size() - 1) / 2]);
        vector<int> left;
        for (int i = 0; i < (nums.size() - 1) / 2; i++) left.push_back(nums[i]);
        vector<int> right;
        for (int i = (nums.size() - 1) / 2 + 1; i < nums.size(); i++) right.push_back(nums[i]);
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/