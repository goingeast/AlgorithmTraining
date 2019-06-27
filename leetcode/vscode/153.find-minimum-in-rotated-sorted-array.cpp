/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
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
            }
        }
        return nums[left];
    }
};

