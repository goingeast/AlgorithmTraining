/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 *
 * https://leetcode.com/problems/the-skyline-problem/description/
 *
 * algorithms
 * Hard (31.06%)
 * Total Accepted:    86.8K
 * Total Submissions: 278.3K
 * Testcase Example:  '[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]'
 *
 * A city's skyline is the outer contour of the silhouette formed by all the
 * buildings in that city when viewed from a distance. Now suppose you are
 * given the locations and height of all the buildings as shown on a cityscape
 * photo (Figure A), write a program to output the skyline formed by these
 * buildings collectively (Figure B).
 * ⁠   
 * 
 * The geometric information of each building is represented by a triplet of
 * integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and
 * right edge of the ith building, respectively, and Hi is its height. It is
 * guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You
 * may assume all buildings are perfect rectangles grounded on an absolutely
 * flat surface at height 0.
 * 
 * For instance, the dimensions of all buildings in Figure A are recorded as: [
 * [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .
 * 
 * The output is a list of "key points" (red dots in Figure B) in the format of
 * [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key
 * point is the left endpoint of a horizontal line segment. Note that the last
 * key point, where the rightmost building ends, is merely used to mark the
 * termination of the skyline, and always has zero height. Also, the ground in
 * between any two adjacent buildings should be considered part of the skyline
 * contour.
 * 
 * For instance, the skyline in Figure B should be represented as:[ [2 10], [3
 * 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].
 * 
 * Notes:
 * 
 * 
 * The number of buildings in any input list is guaranteed to be in the range
 * [0, 10000].
 * The input list is already sorted in ascending order by the left x position
 * Li.
 * The output list must be sorted by the x position.
 * There must be no consecutive horizontal lines of equal height in the output
 * skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not
 * acceptable; the three lines of height 5 should be merged into one in the
 * final output as such: [...[2 3], [4 5], [12 7], ...]
 * 
 * 
 */
class Edge {
public:
    Edge(bool isStart, int value, int height) : isStart(isStart), value(value), height(height){
        
    }   
    bool isStart;
    int value;
    int height;
    
    bool operator<(const Edge& other) const{
        if(value < other.value){
            return true;
        }else if(value == other.value){
            if( isStart == other.isStart){
                return height < other.height;
            }else{
                return isStart;
            }
        }
        
        return false;
    }
};


class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Edge> height;
        for (auto &b : buildings) {
            height.emplace_back(true, b[0], b[2]);
            height.emplace_back(false, b[1], b[2]);
        }
        sort(height.begin(), height.end());
        multiset<int> heap;
        heap.insert(0);
        vector<pair<int, int>> res;
        int pre = 0, cur = 0;
        for (auto &h : height) {
            cout << '{' << h.isStart << ',' << h.value << ',' << h.height << '}' << endl;
            if (h.isStart) {
                heap.insert(h.height);
            } else {
                heap.erase(heap.find(h.height));
            }   
            cur = *heap.rbegin();
            if (cur != pre) {
                cout << '{' << h.value << ',' << cur << '}' << endl;
                res.push_back({h.value, cur});
                pre = cur;
            }
        }
        return res; 
    }
};

class Solution2 {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> height;
        for (auto &b : buildings) {
            height.emplace_back(b[0], -b[2]);
            height.emplace_back(b[1], b[2]);
        }
        sort(height.begin(), height.end());
        multiset<int> heap;
        heap.insert(0);
        vector<pair<int, int>> res;
        int pre = 0, cur = 0;
        for (auto &h : height) {
            cout << '{' << h.first << ',' << h.second << '}' << endl;

            if (h.second < 0) {
                heap.insert(-h.second);
            } else {
                heap.erase(heap.find(h.second));
            }   
            cur = *heap.rbegin();
            if (cur != pre) {
                res.push_back({h.first, cur});
                pre = cur;
            }
        }
        return res; 
    }
};

