// Description
// Given a binary tree, count the number of uni-value subtrees.

// A Uni-value subtree means all nodes of the subtree have the same value.
 
// Example
// Example1

// Input:  root = {5,1,5,5,5,#,5}
// Output: 4
// Explanation:
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
// Example2

// Input:  root = {1,3,2,4,5,#,6}
// Output: 3
// Explanation:
//               1
//              / \
//             3   2
//            / \   \
//           4   5   6

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given tree
     * @return: the number of uni-value subtrees.
     */
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        isUnival(root, -1, res);
        return res;
    }
    bool isUnival(TreeNode* root, int val, int& res) {
        if (!root) return true;
        bool left = isUnival(root->left, root->val, res); 
        bool right = isUnival(root->right, root->val, res);
        if(left == false || right == false) return false;
        ++res;
        return root->val == val;
    }
};