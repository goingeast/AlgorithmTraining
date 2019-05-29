class Solution {
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    // 用dp[i][k][target]表示前i个数里选k个和为k的方案数。
    public:
    
    int  kSum(vector<int>&A, int k, int target) {
        int n = A.size();
        //int f[n + 1][k + 1][target + 1];
        //f[n + 1][k + 1][target + 1] = {};
        vector<vector<vector<int>>> f(n+1, vector<vector<int>>(k+1, vector<int>(target+1, 0)));

        for (int i = 0; i < n + 1; i++) {
            f[i][0][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k && j <= i; j++) {
                for (int t = 1; t <= target; t++) {
                    f[i][j][t] = 0;
                    if (t >= A[i - 1]) {
                        f[i][j][t] = f[i - 1][j - 1][t - A[i - 1]];
                    }
                    f[i][j][t] += f[i - 1][j][t];
                } // for t
            } // for j
        } // for i
        //return f[n][k][target];
        int ans = 0;
        for(int i = 1; i <= k; ++i){
            ans += f[n][i][target];
        }
        return ans;
    }
};