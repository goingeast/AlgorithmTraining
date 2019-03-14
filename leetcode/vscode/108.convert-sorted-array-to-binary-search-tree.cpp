/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (49.27%)
 * Total Accepted:    240K
 * Total Submissions: 486.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given an array where elements are sorted in ascending order, convert it to a
 * height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted array: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
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


/* -------------------------------- Solution -------------------------------- */
/* 因为排序好的数组是中序遍历的结果，而中点是前序的根节点，通过中点分成左右子树，递归生成树  */
/* ----------------------------- Time Complexity ---------------------------- */
/* ---------------------------------- O(n) ---------------------------------- */

TimeComplexity: O(N)

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return preOrder(nums, 0, nums.size() -1);
    }

    TreeNode* preOrder(vector<int>& nums, int left, int right){
        if(left > right) return NULL;

        int mid = left + (right - left)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = preOrder(nums, left, mid -1 );
        root->right = preOrder(nums, mid + 1, right);
        return root;
    }
};

