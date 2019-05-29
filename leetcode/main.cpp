#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <map>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <functional>

using namespace std;

//#include "../facebook/KSum.cpp"
#include "../others/subset_sum.cpp"

int main(){
    Solution s;
    vector<vector<int>> station = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    vector<vector<int>> station2 ={{0,2,3},{2,5,3}};
    vector<vector<int>> station3 ={{1,2,1},{1,2,2},{1,2,3}};
    vector<int> array = {3, 34, 4, 12, 5, 2};
    //cout << s.encode("aaaaaaaaaa");
    //cout << isCircle("GLLLLGGRGLLLLGGRGLLLLGGRGLLLLGGR");
    // s.addRange(1, 10);
    // s.addRange(12, 14);
    // s.removeRange(3, 5);
    // s.printMap();

    cout << s.kSum(array, 6, 9);

    // vector<vector<string>> m1 = {{"A","B", "C", "D"},
    //                              {"A","B", "D"},
    //                              {"A","C", "D"},
    //                              {"A","B", "C", "D"}};
    // TFIDF s;
    // s.preprocess(m1);
    // vector<string> q = {"A", "B", "C"};
    // vector<int> a = s.topK(q, 2);
    // cout << a[0] << a[1] << endl;
    // cout << s.sumOfDiv(220) << '=' << s.sumOfDiv(284);
    
    
    TaskScheduler ts;
    shared_ptr<Task> t = std::make_shared<Task>("ee1", 5, message);
    cout << "dd" << endl;
    ts.schedule(t);
    cout << "dd1" << endl;
    ts.stop();
    return 1;
};