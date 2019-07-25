/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            switch (c)
            {
            case '}':
                if(st.empty() || st.top() != '{') {
                    return false;
                }
                st.pop();
                break;
            case ']':
                if(st.empty() || st.top() != '[') {
                    return false;
                }
                st.pop();
                break;
            case ')':
                if(st.empty() || st.top() != '(') {
                    return false;
                }
                st.pop();
                break;
            default:
                st.push(c);
                break;
            }
        }
        return st.empty();
    }
};

