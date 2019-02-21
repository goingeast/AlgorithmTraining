// Description

// There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.
// Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.
// For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.
// Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

// If there isn't such day, output -1.
// The given array will be in the range [1, 20000].
// Have you met this question in a real interview?  Yes
// Problem Correction
// Example
// Given flowers = [1,3,2], k = 1, return 2.

// Explanation: 
// In the second day, the first and the third flower have become blooming.
// Given flowers = [1,2,3], k = 1, return -1


// 暴力 搜索，创建花状态的数组，index是花的位置。每一天更新对应花的状态，然后找左右K个位置，如果有花开放，然后查找之间是否没有花开放。
// 用set，快速查找左右最近的开花位置。检查是否满足距离条件
class Solution {
public:
    /**
     * @param flowers: the place where the flower will open in that day
     * @param k:  an integer
     * @return: in which day meet the requirements
     */
    int kEmptySlots(vector<int> &flowers, int k) {
        vector<bool> f(flowers.size(), false);
        
        for(int i = 0; i < flowers.size(); ++i){
            int x = flowers[i]-1;
            f[x] = true;
            
            int left = x - k - 1;
            if(left >=0 && f[left]){
                int j = left + 1;
                while(j < x){
                    if(f[j] == true){
                        break;
                    }
                    j++;
                }
                if(j == x) return i+1;
            }
            int right = x + k +1;
            if(right < f.size() && f[right]){
                int j = right - 1;
                while(j > x) {
                    if(f[j] == true){
                        break;
                    }
                    j--;
                }
                if(j == x) return i+1;
            }
        }
        
        return -1;
    }
};