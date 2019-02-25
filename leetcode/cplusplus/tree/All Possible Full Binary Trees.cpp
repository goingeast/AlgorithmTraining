// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

// Return a list of all possible full binary trees with N nodes.  Each element of the answer is the root node of one possible tree.

// Each node of each tree in the answer must have node.val = 0.

// You may return the final list of trees in any order.

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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0) return {};
        if(N == 1) return {new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i = 1; i < N; i += 2) {
            for(auto l : allPossibleFBT(i)){
                for(auto r : allPossibleFBT(N-i-1)){
                    TreeNode* temp = new TreeNode(0);
                    temp->left = l;
                    temp->right = r;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};

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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0) return {};
        vector<vector<TreeNode*>> dp(N+1);
        dp[1] = {new TreeNode(0)};
        for(int i = 3; i <= N; i += 2){
            for(int j = 1; j < i; j += 2) {
                int k = i - j -1;
                
                for(auto& l : dp[j]){
                    for(auto& r : dp[k]){
                        TreeNode* temp = new TreeNode(0);
                        
                        temp->left = l;
                        temp->right = r;
                        
                        dp[i].push_back(temp);
                    }
                }
            }
            
        }
        
        return dp[N];
    }
};