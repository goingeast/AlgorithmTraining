// Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. 
// Return the maximum valued number you could get.

class Solution {
public:
    /**
     * @param num: a non-negative intege
     * @return: the maximum valued number
     */
    int maximumSwap(int num) {
        string numbers = to_string(num);
        vector<int> mp(10, 0);
        int res = num;
        // record the each number's low position
        for(int i = 0; i < numbers.size(); i++){
            mp[numbers[i] - '0'] = i;
        }
        // from high digit, check if any numbers bigger than it are at low position
        for(int i = 0; i < numbers.size(); i++){
            for(int k = 9; k > numbers[i]-'0'; --k) {
                if(mp[k] > i) {
                    swap(numbers[i], numbers[mp[k]]);
                    return stoi(numbers);
                }
            }
        }
        return res;
    }
};