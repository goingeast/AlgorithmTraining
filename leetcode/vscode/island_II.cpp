class Map {
public:
    Map(vector<vector<int>> grid):grid(grid){
        M = grid.size();
        N = grid[0].size();
        roots = vector<int>(M*N, -1);
    }
    int addFront(int x, int y) {
        grid[x][y] = 1;
        int cnt = 0;
        int k = key(x, y);

        if(roots[k] == -1){ 
            roots[k] = k;
            ++cnt;
        }

        for(auto dir : dirs) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            if(x >= 0 && x < M && y >= 0 && y <N && roots[key(newX, newY)] != -1) {
                int p = findRoot(key(newX, newY));
                int q = findRoot(key(x, y));

                if(p != q){
                    roots[p] = q;
                    --cnt;
                }
            }
        }
        return cnt;
    }

private:
    int key(int x, int y){
        return x * N + y;
    }
    int findRoot( int key) {
        while(key != roots[key]){
            key = roots[key];
        }
        return key;
    }
    int M;
    int N;
    vector<int> roots;
    vector<vector<int>> grid;
    vector<vector<int>> dirs = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
   
    
};
