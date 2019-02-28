// You have a list of words and a pattern, and you want to know which words in words matches the pattern.

// A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

// (Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

// Return a list of the words in words that match the given pattern. 

// You may return the answer in any order.

 

// Example 1:

// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
// since a and b map to the same letter.

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto& word : words){
            if(match(word, pattern)){
                ans.push_back(word);
            }
        }
        return ans;
    }
    
    bool match(string a, string b){
        vector<int> mapA(256, -1);
        vector<int> mapB(256, -1);
        if(a.size() != b.size()) return false;
        for(int i = 0; i < a.size(); ++i){
            if(mapA[a[i]] != mapB[b[i]]) return false;
            mapA[a[i]]= i;
            mapB[b[i]]= i;
        }
        return true;
    }
};