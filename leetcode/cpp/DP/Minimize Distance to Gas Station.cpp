class Solution {
public:
    /**
     * @param stations: an integer array
     * @param k: an integer
     * @return: the smallest possible value of D
     */
    double minmaxGasDist(vector<int> &stations, int k) {
        // Write your code here
        int size = stations.size() - 1;
        // sort(stations.begin(), stations.end());

        vector<vector<double>> dp(size, vector<double>(k + 1, INT_MAX));
        for (int i = 0; i <= k; i++) {
            dp[0][i] = (double) (stations[1] - stations[0]) / (i + 1);
            cout << "<" << dp[0][i] << ">";
            for (int j = 1; j < size; j++) {
                for (int h = 0; h <= i; h++) {
                    dp[j][i] = min(dp[j][i], max((double) (stations[j + 1] - stations[j]) / (i - h + 1), dp[j - 1][h]));
                    cout << "<" << dp[j][i] << ">";
                }
                cout << endl;
            }
            cout << endl;
        }
        for(int i = 0; i < dp.size(); ++i){
            for(int j=0; j < dp[0].size(); ++j){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[size - 1][k];
    }
};