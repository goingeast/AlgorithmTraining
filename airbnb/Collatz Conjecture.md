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

    for(int i = 1; i <= num; ++i) {
        res = max(res, findSteps(i));
    }
    return res;
}


```