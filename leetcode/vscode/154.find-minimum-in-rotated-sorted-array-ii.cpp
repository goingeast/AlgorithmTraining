/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right){
            int mid = left + (right -left)/2;
            if(nums[mid] < nums[right]){
                right = mid;
            } else if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else{
                right--;
            }
        }
        return nums[left];
    }
};

