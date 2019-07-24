/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lcaDeepestLeaves_(root).first;
    }

    pair<TreeNode*, int> lcaDeepestLeaves_(TreeNode* root) {
        if(root == NULL) return {NULL, 0};
        auto left = lcaDeepestLeaves_(root->left);
        auto right = lcaDeepestLeaves_(root->right);
        TreeNode* tmp = root;
        if( left.second > right.second) {
            tmp = left.first;
        } else if(left.second < right.second){
            tmp = right.first;
        }
        return {tmp, max(left.second, right.second)+1};
    }
};

