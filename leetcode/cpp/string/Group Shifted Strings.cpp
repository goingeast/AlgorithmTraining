// Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

// "abc" -> "bcd" -> ... -> "xyz"
// Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

// For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
// Return:

// [
//   ["abc","bcd","xyz"],
//   ["az","ba"],
//   ["acef"],
//   ["a","z"]
// ]
 

// Note: For the return value, each inner list's elements must follow the lexicographic order.

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string, multiset<string>> m;
        for (auto a : strings) {
            string t = "";
            for (char c : a) {
                t += to_string((c - a[0] + 26) % 26) + ",";
            }
            m[t].insert(a);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(vector<string>(it->second.begin(), it->second.end()));
        }
        return res;
    }
};