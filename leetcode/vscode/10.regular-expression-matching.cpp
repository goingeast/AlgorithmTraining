/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> res(m + 1, vector<bool>(n + 1, false));
        res[0][0] = true; //s[0..i-1] p[0..j-1]
        for(int i = 2; i <= n; ++i){
            if('*' == p[i-1] && res[0][i-2]) {
                res[0][i] = true;
            }
        }

        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                if(p[j-1] != '*') {
                    res[i][j] = res[i-1][j-1] && (s[i-1] == p[j-1] || '.' == p[j-1]);
                } else {
                    res[i][j] = res[i][j-2] /*match zero */|| (res[i-1][j] && (s[i-1] == p[j-2] || '.' == p[j-2]));
                }
            }
        }

        return res[m][n];
    }
};

