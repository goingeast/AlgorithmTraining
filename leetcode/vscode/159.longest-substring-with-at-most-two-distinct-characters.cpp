/*
 * @lc app=leetcode id=159 lang=cpp
 *
 * [159] Longest Substring with At Most Two Distinct Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/description/
 *
 * algorithms
 * Hard (46.40%)
 * Total Accepted:    67.7K
 * Total Submissions: 145.7K
 * Testcase Example:  '"eceba"'
 *
 * Given a string s , find the length of the longest substring t  that contains
 * at most 2 distinct characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "eceba"
 * Output: 3
 * Explanation: t is "ece" which its length is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "ccaabbb"
 * Output: 5
 * Explanation: t is "aabbb" which its length is 5.
 * 
 */
class Solution {
public:
    const int N = 2;
    int lengthOfLongestSubstringTwoDistinct(string s) {
       
        unordered_map<int, int> map; // char vs index
        int left = 0; 
        int ans = 0;
        for(int r = 0; r < s.size(); ++r){
            map[s[r]] = r;
            
            while(map.size() > N){
                if(left == map[s[left]]){
                    map.erase(s[left]);
                }
                left++; // have to move left one by one as there are some other char in the range of two same char
            }
 
            ans = max(ans, r - left +1);   
            
        }
        return ans;
    }
};

