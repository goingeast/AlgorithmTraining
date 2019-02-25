// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//       1
//     1 1
//     1 1
//     1 1   1
// 1   1 1 1 1
// 1 1 1 1 1 1

// The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

// Example:

// Input: [2,1,5,6,2,3]
// Output: 10


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int m = 0;
        heights.push_back(0);
        
        for(int i =0; i < heights.size(); ++i) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int index = st.top(); st.pop();
                int height = heights[index];
                
                m = max(m, height * (st.empty()? i : i - 1 - st.top()));
            }
            st.push(i);
        }
        return m;
    }
};