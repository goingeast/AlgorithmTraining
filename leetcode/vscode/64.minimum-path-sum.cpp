/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (45.55%)
 * Total Accepted:    211K
 * Total Submissions: 462.4K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                }else if(i == 0 && j > 0){
                    // left side
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }else if(j == 0 && i > 0){
                    // up side
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }else {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

