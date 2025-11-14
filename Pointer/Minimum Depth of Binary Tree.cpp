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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        if (root->left == nullptr || root->right == nullptr) {
            return 1 + ((root->left == nullptr) ? minDepth(root->right) : minDepth(root->left));
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/