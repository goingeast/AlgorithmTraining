/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 *
 * https://leetcode.com/problems/hand-of-straights/description/
 *
 * algorithms
 * Medium (48.38%)
 * Total Accepted:    17K
 * Total Submissions: 35K
 * Testcase Example:  '[1,2,3,6,2,3,4,7,8]\n3'
 *
 * Alice has a hand of cards, given as an array of integers.
 * 
 * Now she wants to rearrange the cards into groups so that each group is size
 * W, and consists of W consecutive cards.
 * 
 * Return true if and only if she can.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
 * Output: true
 * Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].
 * 
 * Example 2:
 * 
 * 
 * Input: hand = [1,2,3,4,5], W = 4
 * Output: false
 * Explanation: Alice's hand can't be rearranged into groups of 4.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= hand.length <= 10000
 * 0 <= hand[i] <= 10^9
 * 1 <= W <= hand.length
 * 
 * 
 */
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        
        map<int, int> freq;

        for(int i = 0; i < hand.size(); ++i){
            freq[hand[i]]++;
        }
        while (!freq.empty()) {
            auto it = freq.begin();
            int start = it->first;
            for (int j = 0; j < W; ++j) {        
                if (it == freq.end() || it->first != start + j) 
                    return false;
                auto prev = it++;
                if (--(prev->second) == 0) 
                    freq.erase(prev);
            }
        }
        return true;
    }
};

