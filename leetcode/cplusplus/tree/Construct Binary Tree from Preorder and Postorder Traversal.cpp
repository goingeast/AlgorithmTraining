// Return any binary tree that matches the given preorder and postorder traversals.

// Values in the traversals pre and post are distinct positive integers.

 

// Example 1:

// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
 

// Note:

// 1 <= pre.length == post.length <= 30
// pre[] and post[] are both permutations of 1, 2, ..., pre.length.
// It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.


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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return constructFromPrePost(pre, 0, pre.size()-1, post, 0, post.size()-1);
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, int preL, int preR, vector<int>& post, int postL, int postR) {
        if(preL == preR) return new TreeNode(pre[preL]);
        if(preL > preR) return NULL;
        
        TreeNode* root = new TreeNode(pre[preL]);
        preL++;
        postR--;
        
        int postNext;
        
        for(int i = postL; i <= postR; ++i){
            if(post[i] == pre[preL]){
                postNext = i - postL;
                break;
            }
        }
        
        root->left = constructFromPrePost(pre, preL, preL+postNext, post, postL, postL+postNext);
        root->right = constructFromPrePost(pre, preL + postNext +1, preR, post, postL + postNext + 1, postR);
        
        return root;
        
    }
};