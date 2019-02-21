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