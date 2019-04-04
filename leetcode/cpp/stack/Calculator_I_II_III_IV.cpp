// Implement a basic calculator to evaluate a simple expression string.
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negativeintegers and empty spaces .

// Example 1:

// Input: "1 + 1"
// Output: 2
// Example 2:

// Input: " 2-1 + 2 "
// Output: 3
// Example 3:

// Input: "(1+(4+5+2)-3)+(6+8)"
// Output: 23
// Note:

// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.

/* ----------------------------- Calculator III ----------------------------- */
// Implement a basic calculator to evaluate a simple expression string.
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
// The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces . The integer division should truncate toward zero.
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].

// Some examples:
// "1 + 1" = 2
// " 6-4 / 2 " = 4
// "2*(5+5*2)/3+(6/2+8)" = 21
// "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
class Solution {
public:
    int calculate(string& s) {
        int n = s.size(), num = 0, curRes = 0, res = 0;
        char op = '+';
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = num * 10 + (c - '0');
            } else if (c == '(') { // find substring in the parentheses
                int j = i+1, cnt = 0;
                while(i < n) {
                    if (s[i] == '(') ++cnt;
                    if (s[i] == ')') --cnt;
                    if (cnt == 0) break;
                    ++i;
                }
                num = calculate(s.substr(j, i - j));
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i == n - 1) {
                switch (op) { // calcluate previous result
                    case '+': curRes += num; break;
                    case '-': curRes -= num; break;
                    case '*': curRes *= num; break;
                    case '/': curRes /= num; break;
                }
                // update final result if we can, otherwise need wait * and / to be done
                if (c == '+' || c == '-' || i == n - 1) { 
                    res += curRes;
                    curRes = 0;
                }
                op = c;
                num = 0;
            }
        }
        return res;
    }
};