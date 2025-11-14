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
    void DFS(TreeNode *root, int targetSum, int curSum, bool &flag) {
        if (root == nullptr) return;
        curSum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (curSum == targetSum) flag = true;
            return;
        }
        DFS(root->left, targetSum, curSum, flag);
        DFS(root->right, targetSum, curSum, flag);
        curSum -= root->val;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        DFS(root, targetSum, 0, flag);
        return flag;
    }
};

// https://leetcode.com/problems/path-sum/description/