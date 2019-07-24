/*
 * @lc app=leetcode id=921 lang=cpp
 *
 * [921] Minimum Add to Make Parentheses Valid
 */
class Solution {
public:
    int minAddToMakeValid(string S) {
        int leftBalance = 0;
        int rightBalance = 0;
        for (auto c : S) {
            if(c == '(') {
                leftBalance++;
            } else {
                if(leftBalance == 0){
                    rightBalance++;
                } else {
                    leftBalance--;
                }
            }
        }
        return leftBalance + rightBalance;
    }
};

