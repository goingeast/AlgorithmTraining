// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// The update(i, val) function modifies nums by updating the element at index i to val.

// Example:

// Given nums = [1, 3, 5]

// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
// Note:

// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.
class NumArray {
public:
    NumArray(vector<int> nums) {
        data.resize(nums.size(), 0);
        bit.resize(nums.size()+1, 0);
        
        for(int i = 0; i < nums.size(); ++i){
            update(i , nums[i]);
        }
  
    }
    
    void update(int i, int val) {
        int diff = val - data[i];
        int idx = i+1;
        while(idx < bit.size()){
            
            bit[idx] += diff;
            
            idx += idx & -idx;
        }
        
        data[i] = val;
    }
    
    int sumRange(int i, int j) {
        return getSum(j) - getSum(i-1);   
    }
    
    int getSum(int i){
        
        int idx = i+1;
        int sum = 0;
        while(idx > 0){
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
    
    int readSingle(int i){
        int idx = i+1;
        int sum = bit[idx];
        
        if(idx > 0) {
            int z = idx - (idx & -idx);
            idx--;

            //cout << idx << "="<<  z;
            while(idx != z){
                sum -= bit[idx];
                idx -= (idx & -idx);
            }
        }
        
        return sum;
    }
    
    
    private:
    vector<int> data;
    vector<int> bit;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */