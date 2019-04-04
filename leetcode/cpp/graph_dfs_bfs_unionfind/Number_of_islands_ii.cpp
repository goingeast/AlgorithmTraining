/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class UnionFind {
    public:
    UnionFind(vector<int>& parent):parent(parent){
        //for(int i = 0; i < parent.size(); ++i){
        //    parent[i] = i;
        //}
    }
    
    bool unit(int p, int q){
        int newP = find(p);
        int newQ = find(q);
        
        if(newP != newQ){
            parent[newP] = newQ;
            return true;
        }
        return false;
    }
    
    int find(int p){
        while(p != parent[p]){
            p = parent[p];
        }
        return p;
    }
    
    private:
    vector<int>& parent;
};

class Solution {
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        vector<int> res;
        int cnt = 0;
        vector<int> roots(m * n, -1);
        
        UnionFind uf(roots);
        
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (auto a : operators) {
            int id = n * a.x + a.y;
            if (roots[id] == -1) {
                roots[id] = id;
                ++cnt;
            }
            for (auto dir : dirs) {
                int x = a.x + dir[0], y = a.y + dir[1], cur_id = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || roots[cur_id] == -1) continue;
                if (uf.unit(cur_id, id)) {
                    --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    
};