#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

#include "./vscode/471.encode-string-with-shortest-length.cpp"

int main(){
    Solution s;
    vector<vector<int>> station = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> station2 ={{0,2,3},{2,5,3}};
    vector<vector<int>> station3 ={{1,2,1},{1,2,2},{1,2,3}};
    vector<int> array = {7,2,5,10,8};
    cout << s.encode("aaaaaaaaaa");

    return 1;
};