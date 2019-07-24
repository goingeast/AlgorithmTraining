/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> bfs;
        bfs.push(s);
        bool isFound = false;
        unordered_set<string> isVisited;
        isVisited.insert(s);

        while(!bfs.empty()) {
            string node = bfs.front(); bfs.pop();
            if(isValid(node)){
                isFound = true;
                res.push_back(node);
            }
            if(isFound) continue;
            for (size_t i = 0; i < node.size(); i++) {
                if(isalpha(node[i])) continue;
                string newNode = node.substr(0, i) + node.substr(i+1);
                if(!isVisited.count(newNode)){
                    bfs.push(newNode);
                    isVisited.insert(newNode);
                }
            }
        }

        return res;
    }

    bool isValid(string s) {
        int leftBalance = 0;
        for(auto c : s) {
            if(c == '(') {
                leftBalance++;
            } else if(c == ')'){
                leftBalance--;
            }
            if(leftBalance < 0){
                return false;
            }
        }
        return leftBalance == 0;
    }

   
};

