/*
 * @lc app=leetcode id=750 lang=cpp
 *
 * [750] Number Of Corner Rectangles
 *
 * https://leetcode.com/problems/number-of-corner-rectangles/description/
 *
 * algorithms
 * Medium (64.00%)
 * Total Accepted:    17.6K
 * Total Submissions: 27.4K
 * Testcase Example:  '[[0,1,0],[1,0,1],[1,0,1],[0,1,0]]'
 *
 * Given a grid where each entry is only 0 or 1, find the number of corner
 * rectangles.
 * 
 * A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned
 * rectangle. Note that only the corners need to have the value 1. Also, all
 * four 1s used must be distinct.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = 
 * [[1, 0, 0, 1, 0],
 * ⁠[0, 0, 1, 0, 1],
 * ⁠[0, 0, 0, 1, 0],
 * ⁠[1, 0, 1, 0, 1]]
 * Output: 1
 * Explanation: There is only one corner rectangle, with corners grid[1][2],
 * grid[1][4], grid[3][2], grid[3][4].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = 
 * [[1, 1, 1],
 * ⁠[1, 1, 1],
 * ⁠[1, 1, 1]]
 * Output: 9
 * Explanation: There are four 2x2 rectangles, four 2x3 and 3x2 rectangles, and
 * one 3x3 rectangle.
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = 
 * [[1, 1, 1, 1]]
 * Output: 0
 * Explanation: Rectangles must have four distinct corners.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of rows and columns of grid will each be in the range [1,
 * 200].
 * Each grid[i][j] will be either 0 or 1.
 * The number of 1s in the grid will be at most 6000.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int countCornerRectangles1(vector<vector<int>>& grid) {
        // 两行两行便利，然后利用公式 n(n-1)/2
        int m = grid.size(), n = grid[0].size(), res = 0;
        for(int i = 0 ; i< m; ++i){
            for(int j = i+1; j < m; ++j){
                int count = 0;
                for(int k = 0; k < n; ++k){
                    if(grid[i][k] == grid[j][k] && grid[i][k] == 1){
                        count++;
                    }
                }
                res += (count-1)*count/2;
            }
        }
        return res;
    }

    int countCornerRectangles(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<bitset<200>> g(n);
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    g[i][j] = true;
                }
            }
        }
        
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = i + 1; j < grid.size(); ++j)
            {
                auto tmp = g[i] & g[j];
                int cnt = tmp.count();
                ans += (cnt - 1) * cnt / 2;
            }
        }
        return ans;
    }
};

