class Solution{
int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        
        // dp[i][j] = d[i-1][j] + dp[i][j-1]
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                dp[j] += dp[j -1];
            }
        }
        return dp[n -1];
    }
};

