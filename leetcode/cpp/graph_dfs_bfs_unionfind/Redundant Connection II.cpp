// In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

// The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

// The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

// Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

// Example 1:
// Input: [[1,2], [1,3], [2,3]]
// Output: [2,3]
// Explanation: The given directed graph will be like this:
//   1
//  / \
// v   v
// 2-->3
// Example 2:
// Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
// Output: [4,1]
// Explanation: The given directed graph will be like this:
// 5 <- 1 -> 2
//      ^    |
//      |    v
//      4 <- 3
// Note:
// The size of the input 2D-array will be between 3 and 1000.
// Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.



class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        
        //1. indegree 2
        //2. circle
        int m = edges.size();
        vector<int> prev, cur;
        vector<int> parent(m*2+1, 0);

        for (auto& edge : edges) {
            if (parent[edge[1]] == 0) {
                parent[edge[1]] = edge[0];
            } else {
                prev = {parent[edge[1]], edge[1]};
                cur = edge;
                edge[1] = 0;
            }
        }
        
        for(int i =0; i< parent.size(); ++i){
            parent[i] = i;
        }
        for (auto& edge : edges) {
       
            int rootP = find(edge[0], parent);
            int rootQ = find(edge[1], parent);
            if( rootP == rootQ) return prev.empty()? edge : prev;
            
            parent[rootP] = rootQ;
        }
        
        return cur;
        
    }
    
    int find(int p, vector<int>& parent){
        while(parent[p] != p){
            p = parent[p];
        }
        return p;
    }
};