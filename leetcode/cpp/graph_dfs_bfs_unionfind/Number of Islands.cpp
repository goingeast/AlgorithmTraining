// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        unordered_set<int> isVisited;
        int m = grid.size();
        int n = grid[0].size();
        int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int res = 0;
        for(int i = 0; i < m; ++i){
            for(int j= 0; j < n; ++j){
                if(grid[i][j] == '0' || isVisited.count(key(i, j , n))) continue;
                res++;
                queue<pair<int, int>> bfs;
                
                bfs.push({i, j});
                isVisited.insert(key(i, j, n));
                
                while(!bfs.empty()){
                    auto node = bfs.front(); bfs.pop();
                    for(auto dir : dirs){
                        int x = node.first + dir[0];
                        int y = node.second + dir[1];
                        if(x >=0 && x < m && y >= 0 && y < n && grid[x][y] == '1' && isVisited.count(key(x, y, n)) == 0){
                            bfs.push({x, y});
                            isVisited.insert(key(x, y, n));
                        }
                    }
                }
                
            }
        }
        return res;
    }
    
    int key(int i, int j, int n){
        return i * n + j;
    }
};