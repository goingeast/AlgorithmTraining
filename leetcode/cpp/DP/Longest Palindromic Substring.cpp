class Solution {
public:
    string longestPalindrome(string s) {
        
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        
        int left = 0;
        int right = 0;
        int len = 0;
        
        for(int i = s.size() -1; i >= 0; --i) {
            for(int j = i; j < s.size(); ++j) {
                if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                }
                   
                if(dp[i][j] && right -left < j -i) {
                    left = i;
                    right = j;
                }
                
            }
        }
                   
        return s.substr(left, right - left +1);
        
        }
};