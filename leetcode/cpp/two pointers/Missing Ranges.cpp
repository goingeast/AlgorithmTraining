/**
* 本参考程序来自九章算法，由 @九章算法助教团队 提供。版权所有，转发请注明出处。
* - 九章算法致力于帮助更多中国人找到好的工作，教师团队均来自硅谷和国内的一线大公司在职工程师。
* - 现有的面试培训课程包括：九章算法班，系统设计班，算法强化班，Java入门与基础算法班，Android 项目实战班，
* - Big Data 项目实战班，算法面试高频题班, 动态规划专题班
* - 更多详情请见官方网站：http://www.jiuzhang.com/?source=code
*/ 

class Solution {
public:
    /*
     * @param nums: a sorted integer array
     * @param lower: An integer
     * @param upper: An integer
     * @return: a list of its missing ranges
     */
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        // write your code here
        if(nums.size()==0){
            if(lower==upper)return {to_string(lower)};
            return {to_string(lower)+"->"+to_string(upper)};
        }
         vector<string> res;
        long long prev = lower - 1;
        for (int i = 0; i <= nums.size(); i++) {
            long long curr = (i == nums.size()) ? upper + 1 : nums[i];
            if (curr - prev >= 2) {
                if (prev + 1 == curr - 1)
                    res.push_back(to_string(prev + 1));
                else
                    res.push_back(to_string(prev + 1)+"->"+to_string(curr - 1));
            }
            prev = curr;
        }
    return res;
    }
};