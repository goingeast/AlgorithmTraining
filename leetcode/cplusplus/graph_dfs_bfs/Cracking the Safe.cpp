// There is a box protected by a password. The password is n digits, where each letter can be one of the first k digits 0, 1, ..., k-1.

// You can keep inputting the password, the password will automatically be matched against the last n digits entered.

// For example, assuming the password is "345", I can open it when I type "012345", but I enter a total of 6 digits.

// Please return any string of minimum length that is guaranteed to open the box after the entire string is inputted.

// Example 1:

// Input: n = 1, k = 2
// Output: "01"
// Note: "10" will be accepted too.
// Example 2:

// Input: n = 2, k = 2
// Output: "00110"
// Note: "01100", "10011", "11001" will be accepted too.

class Solution {
public:
    string crackSafe(int n, int k) {
        string res;
        string cur = string(n, '0');
        unordered_set<string> visited;
        helper(n, k, pow(k, n), visited, cur, res);
        return res;
    }
    void helper(int n, int k, int total, unordered_set<string>& visited, string cur, string& res) {
        if (visited.size() == total || visited.count(cur)) return;
        
        if(res.empty()){
            res = cur;
        }else{
            res += cur.back();
        }
        visited.insert(cur);
        string pre = cur.substr(cur.size() - n + 1, n - 1);
        
        for (int i = k - 1; i >= 0; --i) {
            string newCur = pre + to_string(i);
            helper(n, k, total, visited, newCur, res);
        }
    }
};