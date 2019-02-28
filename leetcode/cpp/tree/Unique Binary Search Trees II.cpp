// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

// Example:

// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

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
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        
        if(n == 0) return {};
        dp[0] = {{NULL}};

        for(int i = 1; i <= n; ++i){
            
            for(int j = 0; j < i; ++j){
                int k = i - j -1;
                
                for(auto& l : dp[j]){
                    for(auto& r: dp[k]){
                        auto root = new TreeNode(j+1);
                        root->left = l;
                        
                        root->right = update(r, j+1);
                        
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
        
        
    }
    
    TreeNode* update(TreeNode* root, int offset){
        
        if(root == NULL) return NULL;
        
        TreeNode* newRoot = new TreeNode(root->val + offset);
        
        newRoot->left = update(root->left, offset);
        newRoot->right = update(root->right,offset);
        return newRoot;
    }
};