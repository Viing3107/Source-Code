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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        res.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        for (auto &x : left) res.push_back(x);
        vector<int> right = preorderTraversal(root->right);
        for (auto &x : right) res.push_back(x);
        return res;
    }
};

// https://leetcode.com/problems/binary-tree-preorder-traversal/description/