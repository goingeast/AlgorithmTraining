#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include <functional>

using namespace std;

//#include "./vscode/471.encode-string-with-shortest-length.cpp"
//#include "../leetcode/cpp/graph_dfs_bfs_unionfind/RemoveParethesis.cpp"
//#include "../leetcode/cpp/graph_dfs_bfs_unionfind/InvertedIndex.cpp"
#include "/Users/hzhao1/AlgorithmTraining/thumbtack/tf_idf.cpp"
#include "/Users/hzhao1/AlgorithmTraining/thumbtack/taskScheduler.cpp"

void message(){
        cout << "send email!" << endl;
}

int main(){
    // //Solution s;
    // vector<vector<int>> station = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    // vector<vector<int>> station2 ={{0,2,3},{2,5,3}};
    // vector<vector<int>> station3 ={{1,2,1},{1,2,2},{1,2,3}};
    // vector<int> array = {7,2,5,10,8};
    // //cout << s.encode("aaaaaaaaaa");
    // //cout << s.removeParenthesis(")(");

    // unordered_map<char, vector<int>> m{{'A', {4, 7, 9, 12, 15}}, {'B', {0, 8, 10, 14, 20}}, {'C', {6, 13, 16, 30, 50}}};
    // unordered_map<char, vector<int>> n{{'A', {0,10}}, {'B', {3, 9}}, {'C', {5,15}}};
    // //cout << minDistance(m);

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