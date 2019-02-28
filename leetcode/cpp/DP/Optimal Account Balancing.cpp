// A group of friends went on holiday and sometimes lent each other money. For example, Alice paid for Bill's lunch for $10. Then later Chris gave Alice $5 for a taxi ride. We can model each transaction as a tuple (x, y, z) which means person x gave person y $z. Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can be represented as [[0, 1, 10], [2, 0, 5]].
// Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.
// Note:
// A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
// Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6.

// Example 1:

// Input:
// [[0,1,10], [2,0,5]]

// Output:
// 2

// Explanation:
// Person #0 gave person #1 $10.
// Person #2 gave person #0 $5.

// Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
 

// Example 2:

// Input:
// [[0,1,10], [1,0,1], [1,2,5], [2,0,5]]

// Output:
// 1

// Explanation:
// Person #0 gave person #1 $10.
// Person #1 gave person #0 $1.
// Person #1 gave person #2 $5.
// Person #2 gave person #0 $5.

// Therefore, person #1 only need to give person #0 $4, and all debt is settled.


int minTransfers(vector<vector<int>> & transactions) {
    unordered_map<int, int> debt;

    for(auto transaction : transactions) {
        debt[transaction[0]] += transaction[2];
        debt[transaction[1]] -= transaction[2];
    }

    vector<int> account;
    for(size_t i = 0; i < debt.size(); ++i){
        if(debt[i]) {
            account.push_back(debt[i]);
        }
    }

    if(account.size() == 0) return 0;
    int len = account.size();
    vector<int> dp(1 << len, INT_MAX/2);

    for(size_t i = 1; i < dp.size(); i++){
        int sum = 0;
        int count = 0;
        for(int j = 0; j < len; j++){
            if((1 << j & i) != 0){
                sum += account[j];
                count++;
            }
        }

        if(sum == 0){
            dp[i] = count -1;
            for(int j = 1; j < i; j++){
                if(((i&j) == j) && d[j] + d[i-j] < d[i]){
                    dp[i] = d[j] + d[i-j];
                }
            }
        }
    }
    return dp.back();
}
