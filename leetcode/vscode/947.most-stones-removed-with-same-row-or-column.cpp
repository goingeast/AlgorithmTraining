/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 *
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
 *
 * algorithms
 * Medium (53.99%)
 * Total Accepted:    14.6K
 * Total Submissions: 27.1K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]'
 *
 * On a 2D plane, we place stones at some integer coordinate points.  Each
 * coordinate point may have at most one stone.
 * 
 * Now, a move consists of removing a stone that shares a column or row with
 * another stone on the grid.
 * 
 * What is the largest possible number of moves we can make?
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
 * Output: 5
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
 * Output: 3
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: stones = [[0,0]]
 * Output: 0
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= stones.length <= 1000
 * 0 <= stones[i][j] < 10000
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
private:
    int n;
    //vector<pair<int, int>> stones;
    map<int, vector<int>> rows, cols;
    unordered_set<int> rowsVisited, colsVisited;
    
    void dfs(int x, vector<vector<int>>& stones) {
        // cout << x <<' ' << r << ' ' << c << endl;
        int r = stones[x][0];
        int c = stones[x][1];

        if(rowsVisited.count(r) && colsVisited.count(c)) return;
        
        if (rowsVisited.count(r) == 0) {
            rowsVisited.insert(r);
            for (int y: rows[r])
                if (y != x && colsVisited.count(stones[y][1])==0)
                    dfs(y,stones); 
        }
        if (colsVisited.count(c) == 0) {
            colsVisited.insert(c);
            for (int y: cols[c])
                if (y != x && rowsVisited.count(stones[y][0]) == 0)
                    dfs(y, stones); 
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        for (int i = 0; i < n; i++) {
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (rowsVisited.find(stones[i][0]) == rowsVisited.end() || 
               colsVisited.find(stones[i][1]) == colsVisited.end()) {
                // cout << i << endl;
                ans++;
                dfs(i, stones);
            }
        }
        
        return n - ans;
    }
};

// class Solution {
// public:
//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         set<pair<int,int>> isVisited;
//         int count = 0;
//         for(int i = 0; i < stones.size(); ++i){
//             if(isVisited.count({stones[i][0], stones[i][1]})){
//                 continue;
//             }
//             count++;
//             queue<pair<int, int>> bfs;
//             bfs.emplace(stones[i][0], stones[i][1]);
//             isVisited.emplace(stones[i][0], stones[i][1]);
//             while(!bfs.empty()){
//                 auto node = bfs.front(); bfs.pop();
//                 for(int j = 0; j < stones.size(); ++j){
//                     if(isVisited.count({stones[j][0], stones[j][1]}) ||
//                         (node.first != stones[j][0] && node.second != stones[j][1])){
//                         continue;
//                     }
//                     bfs.emplace(stones[j][0], stones[j][1]);
//                     isVisited.emplace(stones[j][0], stones[j][1]);
//                 }
//             }
//         }
//         return n-count;
        
//     }
// };

