/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 *
 * https://leetcode.com/problems/minimum-area-rectangle/description/
 *
 * algorithms
 * Medium (49.98%)
 * Total Accepted:    13.1K
 * Total Submissions: 26.2K
 * Testcase Example:  '[[1,1],[1,3],[3,1],[3,3],[2,2]]'
 *
 * Given a set of points in the xy-plane, determine the minimum area of a
 * rectangle formed from these points, with sides parallel to the x and y
 * axes.
 * 
 * If there isn't any rectangle, return 0.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
 * Output: 4
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= points.length <= 500
 * 0 <= points[i][0] <= 40000
 * 0 <= points[i][1] <= 40000
 * All points are distinct.
 * 
 * 
 * 
 */
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> s;
        for (const auto& point : points)
            s[point[0]].insert(point[1]);

        const int n = points.size();
        int min_area = INT_MAX;
        
        for (int i = 0; i < n; ++i)
          for (int j = i + 1; j < n; ++j) {
              
            int x0 = points[i][0];
            int y0 = points[i][1];
            int x1 = points[j][0];
            int y1 = points[j][1];
              
            if (x0 == x1 || y0 == y1) continue; // diagnal horizontal or vertical
            if (!s[x1].count(y0) || !s[x0].count(y1)) continue; // can not find other points
            int area = abs((x0 - x1) * (y0 - y1));
            min_area = min(min_area, area);
          }
        return min_area == INT_MAX ? 0 : min_area;
    }
};

