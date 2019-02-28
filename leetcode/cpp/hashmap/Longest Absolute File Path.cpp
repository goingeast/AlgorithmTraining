class Solution {
public:
    // use hashmap record depth vs folder lens. then update in following
    int lengthLongestPath(string input) {
        int ans =0;
        istringstream ss(input);
        string line = "";
        unordered_map<int, int> hm{{0, 0}};
        
        while(getline(ss, line)){
            int level = line.find_last_of('\t') + 1;
            int len = line.substr(level).size();
            
            if(line.find('.') != string::npos){
                ans = max(ans, hm[level] + len); 
            }else{
                hm[level+1] = hm[level] + len +1; // don't forget '/'
            }
        }
        
        return ans;
    }
};