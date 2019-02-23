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