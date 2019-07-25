/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int res = 0;
        while(i < str.size() && str[i] == ' '){
            i++;
        }
        bool isPositive = true;
        if(str[i] == '-' || str[i] == '+') {
            if(str[i] == '-'){
                isPositive = false;
            }
            i++;
        } 
        
        while(i < str.size()) {
            if(str[i] >= '0' && str[i] <= '9') {
                int remain = (str[i] - '0');
                if(res > (INT_MAX - remain)/10) {
                    return isPositive? INT_MAX : INT_MIN;
                };
                res = res * 10 + remain;
            } else {
                break;
            }
            i++;
        }
        return isPositive? res : -res;
    }
};

