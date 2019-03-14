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