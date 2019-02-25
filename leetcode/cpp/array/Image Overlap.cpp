// Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

// We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.

// (Note also that a translation does not include any kind of rotation.)

// What is the largest possible overlap?

// Example 1:

// Input: A = [[1,1,0],
//             [0,1,0],
//             [0,1,0]]
//        B = [[0,0,0],
//             [0,1,1],
//             [0,0,1]]
// Output: 3
// Explanation: We slide A to right by 1 unit and down by 1 unit.
// Notes: 

// 1 <= A.length = A[0].length = B.length = B[0].length <= 30
// 0 <= A[i][j], B[i][j] <= 1

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<pair<int, int>> LA, LB;
        int N = A.size();
        unordered_map<string, int> count;
        for (int i = 0; i < N * N; ++i) if (A[i / N][i % N] == 1) LA.push_back({i / N , i % N});
        for (int i = 0; i < N * N; ++i) if (B[i / N][i % N] == 1) LB.push_back({i / N , i % N});
        for (auto i: LA) for (auto j: LB) count[key(i.first - j.first, i.second - j.second)]++;
        int res = 0;
        for (auto it: count) res = max(res, it.second);
        return res;
    }
    
    string key(int i, int j){
        return to_string(i)+','+ to_string(j); 
    }
};