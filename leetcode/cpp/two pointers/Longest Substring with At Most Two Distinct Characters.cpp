// Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

// Example 1:

// Input: "eceba"
// Output: 3
// Explanation: t is "ece" which its length is 3.
// Example 2:

// Input: "ccaabbb"
// Output: 5
// Explanation: t is "aabbb" which its length is 5.

class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        if(k == 0) return 0;
        unordered_map<char, int> mp;
        
        int l = 0;
        int r = 0;
        int ans = 0;
        while(r < s.size()){
            mp[s[r]] = r;

            // update left
            while(mp.size() > k) {
                if(mp[s[l]] == l){
                    mp.erase(s[l]);
                }
                l++;
            }
            ans = max(ans, r - l +1);
            r++;
        }
        
        return ans;
    }
};