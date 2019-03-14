#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#include "greedy/Split Array into Consecutive Subsequences.cpp"

int main(){
    Solution s;
    vector<int> station = {1,2,3,4,4,5};
    cout << s.isPossible(station);
  
    return 1;
};