## 回文 Palindrome

- ### 相关题目
[LC 5: Longest Palindromic Substring]()
[LC 516: Longest Palindromic Subsequence]()
[LC 647: Palindromic Substrings]()

- ### 使用DP来解决回文问题。
记录子串状态，减少重复计算。时间复杂度O(n^2).

#### 经典例题：LC 5.
计算最长回文子串。
使用DP记录子串s[i,j] 是否是回文，通过转移方程计算整个字符串。

###### 转移方程：

$$
dp[i][j] = \begin{Bmatrix}
 dp[i+1][j-1] & if\enspace s[i]==s[j] \\ 
 True & if\enspace  j-i<=2
\end{Bmatrix}
$$

#### 经典例题：LC 516.
计算最长回文子序列。
使用DP记录子串s[i,j]中的最长回文，通过转移方程计算整个字符串。
###### 转移方程：
$$
dp[i][j] = \begin{Bmatrix}
 dp[i+1][j-1] & if\enspace s[i]==s[j] \\ 
 max(dp[i+1][j], dp[i][j-1]) & if\enspace  s[i] \ != s[j]
\end{Bmatrix}
$$

##### 模板：

``` c++
/*
 * Trick:
 * 如何从小计算到大？
 * Line: 12, 13, 14, 18
 */
string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int left = 0;
        int right = 0;
        for(int i = s.size()-1; i >= 0; --i) {
            for(int j = i; j < s.size(); ++j) {
                if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                }
                   
                if(dp[i][j] && right - left < j - i) {
                    left = i;
                    right = j;
                }
            }
        }                   
        return s.substr(left, right - left + 1);
    }
    
```

- ### 使用中间开花
有中间向两边伸展。时间复杂度O(n^2)

#### 经典例题 LC 647

计算子串回文的总数。

##### 模板：
 ``` C++
 /*
  * Tricks:
  * 如何向两边延展？
  */
void helper(string s, int i, int j, int& res) {
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
        --i; ++j; ++res;
    }
}

int countSubstrings(string s) {
    if (s.empty()) return 0;
    int n = s.size(), res = 0;
    for (int i = 0; i < n; ++i) {
        helper(s, i, i, res);
        helper(s, i, i + 1, res);
    }
    return res;
}
 ```

