/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */
class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for(auto c : address) {
            if (c == '.'){
                res += "[.]";
            } else {
                res += c;
            }
        }
        return res;
    }
};

