/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.60%)
 * Total Accepted:    389K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
//=====================================================================================
// we use i as first array index, use j as second array index.
// case1 : 第一个数组结束，返回 第二个数组 nums2[j + k - 1], 包括j本身，所以是 k-1；
//         第二个数组结束，返回 第一个数组 nums1[i + k + 1], 包括i本身，所以是 k-1；
// case2 : 如果k等于1. 返回 两个数组中较小的 min(num1[i], nums2[j])
// case3 : 找各自的下个k/2，即nums1[i+k/2-1]，或者nums2[j+k/2-1]，用来决定去舍去哪一半，谁小舍谁。 
//         注意编程技巧如果有数组没有i+k/2-1，或者j+k/2-1, 可以设置为INT_MAX。这样可以满足谁小舍谁。
//=====================================================================================
// This sub function can be used to find kth number in two sorted array.
//=====================================================================================
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        return (findKth(nums1, 0, nums2, 0, (m+n+1)/2) + findKth(nums1, 0, nums2, 0, (m+n+2)/2))*0.5;
    }

    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        int m = nums1.size();
        int n = nums2.size();

        if(i >= m) return nums2[j+k-1];
        if(j >= n) return nums1[i+k-1];

        if(k == 1) return min(nums1[i], nums2[j]);

        int nums1Min = i + k/2 -1 < m ? nums1[i + k/2 -1] : INT_MAX;
        int nums2Min = j + k/2 -1 < n ? nums2[j + k/2 -1] : INT_MAX;

        if(nums1Min < nums2Min){
            return findKth(nums1, i + k/2, nums2, j, k - k/2);
        } else {
            return findKth(nums1, i, nums2, j + k/2, k - k/2);
        }
    }
};

