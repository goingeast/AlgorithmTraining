/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i] 以 i 结尾的最大和
        // dp[i] = max(nums[i], dp[i-1]+nums[i]);
        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        int maxSum = dp[0];
        for (int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i-1], 0) + nums[i];
            maxSum = max(maxSum, dp[i]);
        }
        return maxSum;
    }
};

