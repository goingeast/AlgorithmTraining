cclass UnionFind{
    public:
        UnionFind(int size):parent(size){
            for(int i = 0; i < size; ++i){
                parent[i] = i;
            }
        }
        int find(int p){
            while(parent[p] != p){
                p = parent[p];
            }
            cout << p << endl;
            return p;
        }

        void unite(int p, int q){
            int rootP = find(p);
            int rootQ = find(q);

            parent[p] = q;
        }

        bool isConnected(int p, int q){
            return find(p) == find(q);
        }
    private:
        vector<int> parent;
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf(2000);

        for(auto& edge : edges){
            if(uf.isConnected(edge[0], edge[1])){
                return edge;
            }
            uf.unite(edge[0], edge[1]);
        }
        return {};
    }
};

class Solution {
public:
    vector<int> validTree(vector<vector<int>>& edges) {
        UnionFind uf(2000);

        for(auto& edge : edges){
            if(uf.isConnected(edge[0], edge[1])){
                return false;
            }
        }

        unite(edge[0], edge[1]);
    }
    return true;
};