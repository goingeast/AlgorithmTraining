class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size(); int ret = 0;
        vector<int> count(26, 0);
        int start = 0; int end = 0; int localMaxFreq = 0; 
        for(; end<size; end++){
            localMaxFreq = max(localMaxFreq, ++count[s[end]-'A']);
            while((end-start+1)-localMaxFreq > k) {
                count[s[start]-'A']--;
                start++;
                //localMaxFreq = *(max_element(count.begin(), count.end()));
            }
            ret = max(ret, (end-start+1));
        }
        return ret;
    }
};