/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (34.52%)
 * Total Accepted:    101.3K
 * Total Submissions: 293.1K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * Example 1:
 * 
 * 
 * Input: S = "rabbbit", T = "rabbit"
 * Output: 3
 * Explanation:
 * 
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "babgbag", T = "bag"
 * Output: 5
 * Explanation:
 * 
 * As shown below, there are 5 ways you can generate "bag" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 * 
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        if(s == t ){
            return 1;
        }
        int m = s.size();
        int n = t.size();
        //vector<vector<long>> f(m+1, vector<long>(n+1,0));
        long f[m+1][n+1] = {};
        // 代表 s.substring(0 , i) 和 t.substring(0 ，j) 的最大distinct答案
        for(int i = 0 ; i <= m ; i++){
            f[i][0] = 1;
            //t 为 “”  s有一种变成 “” 全删了
        }
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(s[i - 1] == t[j - 1]){
            // 去前面s找有匹配的个数          只和当前的i 匹配                 
                    f[i][j] = f[i - 1][j] + f[i - 1][j - 1] ;
                }
                else{          //去前面s找有匹配的个数
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        return f[m][n];   
    }
};

