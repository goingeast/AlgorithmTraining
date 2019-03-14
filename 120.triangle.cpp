/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (38.34%)
 * Total Accepted:    171.1K
 * Total Submissions: 444.9K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)
            return 0;
            
        vector<int> f(triangle[triangle.size()-1].size());
        
        f[0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); i++)
            for(int j = triangle[i].size() - 1; j >= 0; j--)
                if (j == 0)
                    f[j] = f[j] + triangle[i][j];
                else if (j == triangle[i].size() - 1)
                    f[j] = f[j-1] + triangle[i][j];
                else
                    f[j] = min(f[j-1], f[j]) + triangle[i][j];
                    
        int ret = INT_MAX;
        for(int i = 0; i < f.size(); i++)
            ret = min(ret, f[i]);
        return ret; 
    }
};

