/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (40.90%)
 * Total Accepted:    194.4K
 * Total Submissions: 473.4K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        // write you code here
        unordered_set<int> map(num.begin(), num.end());
        int ans = 0;
        for (int i = 0; i < num.size(); i++) { 
            if (map.find(num[i]) != map.end()) {
                map.erase(num[i]);
                int pre = num[i] - 1;
                int next = num[i] + 1;
                while (map.find(pre) != map.end()) { 
                map.erase(pre);
                pre--;
                } 
                while (map.find(next) != map.end()) { 
                map.erase(next);
                next++;
                } 
                ans = max(ans, next - pre - 1);
            }
        } 
        return ans;
    }
};

