class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq, need;
        for (int num : nums) ++freq[num];
        for (int num : nums) {
            if (freq[num] == 0) continue;
            cout << "="<< num << endl;
            if (need[num] > 0) {
                cout << "-"<< num << endl;
                --need[num];
                ++need[num + 1];
            } else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                cout << "+"<< num << endl;
                --freq[num + 1];
                --freq[num + 2];
                ++need[num + 3];
            } else {
                return false;
            }
            --freq[num];
        }
        return true;
    }
};