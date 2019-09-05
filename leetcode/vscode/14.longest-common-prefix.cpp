/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string res;
        
        for(int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); ++j) {
                if(i > strs[j].size() || c != strs[j][i]){
                    return res;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};

