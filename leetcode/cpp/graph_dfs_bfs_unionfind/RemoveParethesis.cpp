class Solution {
public:
    string removeParenthesis(string s) {
        int leftbalance = 0;
        string t;
        string res;
        for(auto c : s){
            if(c == '('){
                t.push_back(c);
                leftbalance++;
            }else if(leftbalance >0 && c == ')'){
                t.push_back(c);
                leftbalance--;
            }
        }
        int rightbalance = 0;
        for(int i = t.size()-1; i >= 0; --i){
            if(t[i] == ')'){
                res.push_back(t[i]);
                rightbalance++;
            }else if(rightbalance >0 && t[i] == '('){
                res.push_back(t[i]);
                rightbalance--;
            }
        }
        return string(res.rbegin(), res.rend());
    }
};