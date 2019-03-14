class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string& a, string& b){
            if(a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });
        
        for(auto word : d){
            int i =0;
            for(auto c : s){
                if(i < word.size() && word[i] == c){
                    ++i;
                }
            }
            if(i == word.size()) return word;
        }
        return "";
    }
    
};