/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 *
 * https://leetcode.com/problems/subarray-product-less-than-k/description/
 *
 * algorithms
 * Medium (36.26%)
 * Total Accepted:    26.7K
 * Total Submissions: 73.6K
 * Testcase Example:  '[10,5,2,6]\n100'
 *
 * Your are given an array of positive integers nums.
 * Count and print the number of (contiguous) subarrays where the product of
 * all the elements in the subarray is less than k.
 * 
 * Example 1:
 * 
 * Input: nums = [10, 5, 2, 6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are: [10], [5],
 * [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
 * Note that [10, 5, 2] is not included as the product of 100 is not strictly
 * less than k.
 * 
 * 
 * 
 * Note:
 * 0 < nums.length .
 * 0 < nums[i] < 1000.
 * 0 .
 * 
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // the len of sliding window equals to the number of subarray end with nums[i]
        if (k <= 1) return 0;
        int res = 0, prod = 1, left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            while (prod >= k) prod /= nums[left++];
            res += i - left + 1;
        }
        return res;
    }
};

