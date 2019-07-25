/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string res = "";
        int maxStep = 2*(numRows-1);
        for(int i = 0; i < numRows; ++i) {
            int start = i;
            int step = 2 * (numRows-i-1);
            while(start < s.size()) {
                res += s[start];
                start += step == 0? maxStep:step;
                step = maxStep-step;
            }
        }
        return res;
    }
};

