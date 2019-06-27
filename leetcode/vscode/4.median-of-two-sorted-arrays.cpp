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
    double findMedianSortedArrays_1(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if((m+n) % 2 == 1){
            return findKth(nums1, 0, nums2, 0, (m+n+1)/2);
        }

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

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size();
        int N2 = nums2.size();
        if (N1 < N2) return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.
        
        int lo = 0, hi = N2;
        while (lo <= hi) {
            int mid2 = (lo + hi) / 2;   // Try Cut 2 
            int mid1 = (N1+N2+1)/2 - mid2;  // Calculate Cut 1 accordingly
            
            double L1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];	// Get L1, R1, L2, R2 respectively
            double R1 = (mid1 == N1) ? INT_MAX : nums1[mid1];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
            double R2 = (mid2 == N2) ? INT_MAX : nums2[mid2];
            
            if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
            else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
            else {
                if((N1+N2)%2 == 0){
                    return (max(L1,L2) + min(R1, R2)) / 2;
                } else {
                    return max(L1, L2);
                }
            }
        }
        return -1;
    } 
};



