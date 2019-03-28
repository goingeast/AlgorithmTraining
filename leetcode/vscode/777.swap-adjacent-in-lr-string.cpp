/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 *
 * https://leetcode.com/problems/swap-adjacent-in-lr-string/description/
 *
 * algorithms
 * Medium (32.88%)
 * Total Accepted:    12.8K
 * Total Submissions: 38.8K
 * Testcase Example:  '"X"\n"L"'
 *
 * In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a
 * move consists of either replacing one occurrence of "XL" with "LX", or
 * replacing one occurrence of "RX" with "XR". Given the starting string start
 * and the ending string end, return True if and only if there exists a
 * sequence of moves to transform one string to the other.
 * 
 * Example:
 * 
 * 
 * Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
 * Output: True
 * Explanation:
 * We can transform start to end following these steps:
 * RXXLRXRXL ->
 * XRXLRXRXL ->
 * XRLXRXRXL ->
 * XRLXXRRXL ->
 * XRLXXRRLX
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= len(start) = len(end) <= 10000.
 * Both start and end will only consist of characters in {'L', 'R', 'X'}.
 * 
 * 
 */
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size(), cntL = 0, cntR = 0;
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'R') ++cntR;
            if (end[i] == 'L') ++cntL;
            if (start[i] == 'L') --cntL;
            if (end[i] == 'R') --cntR;
            // order is wrong or word not same
            if (cntL < 0 || cntR < 0 || cntL * cntR != 0) return false;
        }
        return cntL == 0 && cntR == 0;
    }
};

