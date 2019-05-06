## Collatz Conjecture

[Wiki](https://en.wikipedia.org/wiki/Collatz_conjecture)

### Problem statement
Calculate the maximum iteration in the number from [1, N], when all numbers follow the Collatz Conjecture.

> 题目是给你公式,比如偶数的话除 2,奇数的话就变成 3*n+1,对于任何一个正数,数学猜想是最终他会变成 1。每变一步步数加 1,给一个上限,让找出范围内最长步数。


``` C++

int findSteps(int num) {
    if(num <= 1) return 0;

    
}

int findLongestSteps(int num) {
    if(num < 1) return 0;
    int res = 0;
    unordered_map<int, int> cache;
    cache[1] = 1;
    for(int i = 2; i <= num; ++i) {
        int num = i;
        int count = 0;
        while(cache.count(num) == 0){
            count++;
            if(num%2 == 0){
                num /= 2;
            }else{
                num = num*3 +1;
            }
        }
        res = max(res, count+cache[num]);
        cache[num] = count+cache[num];
    }
    return res;
}


```