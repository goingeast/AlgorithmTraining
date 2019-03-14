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
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive2(TreeNode * root) {
        // write your code here
        int res = 0;
        helper(root, res);
        return res;
    }
    pair<int, int> helper(TreeNode* root, int& res) {
        if(root == NULL) return {0, 0};

        auto left = helper(root->left, res);
        auto right = helper(root->right, res);
        int inc = 1;
        int dec = 1;
        
        if(root->left){
            if(root->left->val == root->val + 1){
                inc = max(inc, left.first + 1);    
            }else if(root->left->val == root->val - 1){
                dec = max(dec, left.second + 1);
            }
        }
        
        if(root->right){
            if(root->right->val == root->val + 1){
                inc = max(inc, right.first+1);    
            }else if(root->right->val == root->val - 1){
                dec = max(dec, right.second+1);
            }
        }

        res = max(res, inc + dec - 1);
      
        return {inc, dec};
    }
    
};