class Solution {
public:
    Solution(vector<int> w) {
        sum.push_back(w[0]);
        for(int i = 1 ; i < w.size(); ++i){
            sum.push_back(sum.back() + w[i]);
        }
    }
    
    int pickIndex() {
        int val = rand()%sum.back() + 1;
        int left = 0;
        int right = sum.size()-1;
        while(left <= right){
            int mid= left + (right - left)/2;
            if(sum[mid] == val){
                return mid;
            }else if(sum[mid] < val){
                left = mid + 1;
            }else {
                right = mid -1;
            }
        }
        return left;
    }
    private:
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */