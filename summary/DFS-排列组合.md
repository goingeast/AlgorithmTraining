### 排列组合 DFS

- ### 相关题目
[LC 22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
[LC 17: Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number)

- ### 套路
1. 不定长的组合问题
    1. push_back/pop_back build candidate.
    2. 如果有重复，可以先sort，然后在剪枝
    3. 第一种思路，选择加或者不加。 level = level+1. base case 是 level == candidate.size(), 最后一层才加入所有结果
    4. 第二种思路是 level = i+1. base case 是每次产生就加入。可以剪枝。
2. 定长的排列问题
    1. input, swap来swap去
    2. 如果有重复，可以用hashset去重，不用sort
    3. 注意树的level = level+1
3. 本质是树状图
4. 存在重复有两种剪枝方法
    1. 分叉处直接跳过 subset II， combination sum II。
    2. hashset去重 permutation II
5. 注意满足条件的剪枝。一般情况是树的level等于input array的size，相当于把所有的组合都要计算，但是有些时候可以根据题目的constraint提前剪枝，例

如 Combination II。
``` C++
while(index+1 < nums.size() && nums[index] == nums[index+1])
{
    index++;
}
```
- ### 组合的两种思路，推荐第一种
``` C++
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        combinationSum(candidates, target, res, temp, 0);
        return res;
    }
    
    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& candidate, int index) {
        
        if(0 == target) {
            res.push_back(candidate);
            return;
        }
        
        if(0 > target || index == candidates.size()) {
            return;
        }

        candidate.push_back(candidates[index]);
        combinationSum(candidates, target-candidates[index], res, candidate, index);
        candidate.pop_back();
        
        // 分支, 在此处去重剪枝，思考怎么做
        combinationSum(candidates, target, res, candidate, index+1);
      
    }
};
```

``` C++
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> temp;
        combinationSum(candidates, target, res, temp, 0);
        return res;
        
    }
    
    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& candidate, int index) {
        
        if(0 == target) {
            res.push_back(candidate);
            return;
        } else if(0 > target) {
            return;
        }
        
        for(int i = index; i < candidates.size(); ++i) {
        // 分支，在此处去重剪枝，怎做
            candidate.push_back(candidates[i]);
            combinationSum(candidates, target- candidates[i], res, candidate, i);
            candidate.pop_back();
        }
        
    }
};
```