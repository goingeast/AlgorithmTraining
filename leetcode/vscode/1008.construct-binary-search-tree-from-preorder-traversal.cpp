/*
 * @lc app=leetcode id=1008 lang=cpp
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        int upperbound = INT_MAX;
        return bstFromPreorder(preorder, index, upperbound);
    }

    TreeNode* bstFromPreorder(vector<int>& preorder, int& index, int upperbound) {
        if(index == preorder.size() || preorder[index] > upperbound) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[index++]);

        root->left = bstFromPreorder(preorder, index, root->val);
        root->right = bstFromPreorder(preorder, index, upperbound);

        return root;
    }

};

