/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
class Solution {
public:
    bool isPalindrome(int x) {
        // eg -121, 10, 100
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reversed = 0;
        while(x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        // 12321, because x = 12, reversed = 123,
        return x == reversed || x == reversed/10;
    }
};

