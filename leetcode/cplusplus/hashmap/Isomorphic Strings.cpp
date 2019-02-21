// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m(256, -1);
        vector<int> n(256, -1);
        
        for(int i = 0; i < s.size(); ++i) {
            if(m[s[i]] != n[t[i]]) return false;
            
            m[s[i]] = i;
            n[t[i]] = i;
        }
        
        return true;
    }
};