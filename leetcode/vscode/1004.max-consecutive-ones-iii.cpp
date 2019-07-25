/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int maxLength = 0;
        int left = 0;
        int count = 0;

        for(int i = 0; i < A.size(); ++i) {
            if(A[i] == 0) {                            /*❶*/
                count++;
            }

            while(count > K) {                         /*❷*/
                if(A[left] == 0){
                    count--;
                }
                left++;
            }

            maxLength = max(maxLength, i - left + 1);  /*❸*/
        }
        return maxLength;
    }
};



