### 双指针 三指针

- ### 相关题目
[LC 11：Container With Most Water](https://leetcode.com/problems/container-with-most-water/)

#### 套路
谁小移谁
#### 模板

``` C++
int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int res = 0;
    while(left < right) {

        int minHeight = 0;
        if(height[left] < height[right]){
            minHeight = height[left++];
        }else {
            minHeight = height[right--];
        }
        res = max(res, minHeight * (right - left + 1));
    }
    return res;
}

```

### Sliding Window
- ### 相关题目
[LC 904: Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)

#### 套路
更新右边界，根据条件更新左边界，更新完左边界再更新结果
#### 模板

``` C++
int totalFruit(vector<int>& tree) {
    //two pointer
    int ans = 0;
    unordered_map<int, int> mp;
    int l = 0;
    for(int r = 0; r < tree.size(); ++r){
        
        mp[tree[r]] = r; // update right position
        
        while(mp.size() > 2) {
            if(mp[tree[l]] == l){ // move left to next
                mp.erase(tree[l]);
            }
            l++; 
        }
        ans = max(ans, r - l +1);
    }
    return ans;
}
```