// You have 4 cards each containing a number from 1 to 9. You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.

// Example 1:
// Input: [4, 1, 8, 7]
// Output: True
// Explanation: (8-4) * (7-1) = 24
// Example 2:
// Input: [1, 2, 1, 2]
// Output: False
// Note:
// The division operator / represents real division, not integer division. For example, 4 / (1 - 2/3) = 12.
// Every operation done is between two numbers. In particular, we cannot use - as a unary operator. For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
// You cannot concatenate numbers together. For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        bool res = false;
        vector<double> n(nums.begin(), nums.end());
        judgePoint24(n, res);
        return res;
    }
    
    void judgePoint24(vector<double>& nums, bool& res){
        if(res) return;
        if(nums.size() == 1 && abs(nums[0] - 24) < eps){
            res = true;
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                double p = nums[i];
                double q = nums[j];
                
                vector<double> t = {p+q,p-q, q-p, p*q};
                if(q > eps) t.push_back(p/q);
                if(p > eps) t.push_back(q/p);
                nums.erase(nums.begin() +i);
                nums.erase(nums.begin() + j);
                for(auto newNum : t){
                    nums.push_back(newNum);
                    judgePoint24(nums, res);
                    nums.pop_back();
                }
                nums.insert(nums.begin() +j,  q);
                nums.insert(nums.begin() +i, p);
                
            }
            
        }
    }
    static constexpr double eps = 0.001;
};
