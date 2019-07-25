/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Sequence
 */
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        // diff vs (index vs length)
        const int DEFAULT_LEN = 2;
        if(A.size() < DEFAULT_LEN) return 1;
        unordered_map<int, unordered_map<int, int>> dp;
        int maxLen = DEFAULT_LEN;
        for(int i = 1; i < A.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                int diff = A[j] - A[i];
                if(dp[diff].count(j)) {
                    dp[diff][i] = dp[diff][j] + 1;
                    maxLen = max(maxLen,dp[diff][i]);
                } else {
                    dp[diff][i] = DEFAULT_LEN;
                }
            }
        }
        return maxLen;
    }
};

