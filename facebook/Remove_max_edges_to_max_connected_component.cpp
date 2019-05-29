/*Given an undirected tree which has even number of vertices, we need to remove the maximum number of edges from this tree such that each connected component of the resultant forest has an even number of vertices.*/

class Solution {
    public:
        int removeEdges(TreeNode* root){
            int nodeNum = 0;
            return removeEdges(root, nodeNum);
        }

        
}