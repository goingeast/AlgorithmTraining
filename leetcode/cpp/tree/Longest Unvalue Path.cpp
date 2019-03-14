// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

// Note: The length of path between two nodes is represented by the number of edges between them.

// Example 1:

// Input:

//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
// Output:

// 2
// Example 2:

// Input:

//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
// Output:

// 2

class Solution {
   public:  
     /**
     * @param root: 
     * @return: the length of the longest path where each node in the path has the same value
     * dfs递归左右子树
     */
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = 0;
        getPath(root, res);
        return res;
    }
private:
    int getPath(TreeNode* root, int &res){
        if(root == nullptr) return 0;
        int l = getPath(root->left, res);
        int r = getPath(root->right, res);
        int pl = 0, pr = 0;
        if(root->left && (root->left->val == root->val)) pl = l + 1;
        if(root->right && (root->right->val == root->val)) pr = r + 1;
        res = max(res, pl + pr);
        return max(pl, pr);
    }
};