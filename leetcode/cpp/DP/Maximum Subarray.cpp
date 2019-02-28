// Given an integer array nums, find the contiguous subarray (containing at least one number) 
// which has the largest sum and return its sum.

// Example:

// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Follow up:

// If you have figured out the O(n) solution,
// try coding another solution using the divide and conquer approach, which is more subtle.
class Solution {
    public:
        int maximumSubarray(vector<int>& input){
        // d[i] the largest sum of [0,1]
        vector<int> dp(input.size());
        dp[0] = input[0];
        int ans = input[0];
        for(size_t i = 1; i < input.size(); i++)
        {
            dp[i] = max(dp[i-1] + input[i], input[i]);
            ans = max(ans, dp[i]);
            
        }
        return ans;
    }
};
