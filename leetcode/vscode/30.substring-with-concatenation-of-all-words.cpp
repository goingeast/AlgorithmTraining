/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (23.28%)
 * Total Accepted:    126.9K
 * Total Submissions: 544.3K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.size() == 0) {
            return result;
        }
        
        unordered_map<string, int> hash;
        for (int i = 0; i < words.size(); i++) {
            hash[words[i]]++;
        }
        
        int wSize = words[0].length();
        for (int start = 0; start < wSize; start++) {
            int wCount = 0;
            unordered_map<string, int> slidingWindow;
            for (int i = start; i + wSize <= s.length(); i+=wSize) {
                string word = s.substr(i, wSize);
                if (hash.find(word) == hash.end()) {
                    slidingWindow.clear();
                    wCount = 0;
                } else {
                    wCount++;
                    
                    slidingWindow[word]++;
                    
                    while (hash[word] < slidingWindow[word]) {
                        string removedWord = s.substr(i - (wCount-1) * wSize, wSize);
                        cout << removedWord << " "<< i - (wCount-1) * wSize << endl;
                        slidingWindow[removedWord]--;
                        wCount--;
                    }
                }
                
                if (wCount == words.size()) {
                    result.push_back(i - (wCount - 1) * wSize);
                }
            }
        }
        
        return result;
    }
};

