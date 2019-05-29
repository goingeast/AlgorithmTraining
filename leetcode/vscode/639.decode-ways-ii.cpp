/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 *
 * https://leetcode.com/problems/decode-ways-ii/description/
 *
 * algorithms
 * Hard (24.81%)
 * Total Accepted:    20.6K
 * Total Submissions: 82.6K
 * Testcase Example:  '"*"'
 *
 * 
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping way:
 * 
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 
 * Beyond that, now the encoded string can also contain the character '*',
 * which can be treated as one of the numbers from 1 to 9.
 * 
 * 
 * 
 * 
 * Given the encoded message containing digits and the character '*', return
 * the total number of ways to decode it.
 * 
 * 
 * 
 * Also, since the answer may be very large, you should return the output mod
 * 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * Input: "*"
 * Output: 9
 * Explanation: The encoded message can be decoded to the string: "A", "B",
 * "C", "D", "E", "F", "G", "H", "I".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "1*"
 * Output: 9 + 9 = 18
 * 
 * 
 * 
 * Note:
 * 
 * The length of the input string will fit in range [1, 10^5].
 * The input string will only contain the character '*' and digits '0' - '9'.
 * 
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        const int M = 1000000007;
        long dp[s.length() + 1];
        dp[s.length()+1] = {0};
        dp[0] = 1;
        dp[1] = s[0] =='*' ? 9 : s[0] =='0' ? 0 : 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] =='*') {
                dp[i + 1] = 9 * dp[i];
                if (s[i - 1] == '1')
                    dp[i + 1] = (dp[i + 1] + 9 * dp[i - 1]) % M;
                else if (s[i - 1] == '2')
                    dp[i + 1] = (dp[i + 1] + 6 * dp[i - 1]) % M;
                else if (s[i - 1] == '*')
                    dp[i + 1] = (dp[i + 1] + 15 * dp[i - 1]) % M;
            } else {
                dp[i + 1] = s[i] !='0' ? dp[i] : 0;
                if (s[i - 1] == '1')
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
                else if (s[i - 1] == '2' && s[i] <='6')
                    dp[i + 1] = (dp[i + 1] + dp[i - 1]) % M;
                else if (s[i - 1] == '*')
                    dp[i + 1] = (dp[i + 1] + (s[i] <='6' ? 2 : 1) * dp[i - 1]) % M;
            }
        }
        return (int) dp[s.length()];
    }
};

