### 什么是图

### 图的表示

#### 矩阵 matrix
#### 连接表 adjacency list

``` C++
unordered_map<char, uordered_map<char, int>>  matrixOrAdjacencyList // using char as node labal 
vector<vector<int>> matrix; //using index as node lable

unordered_map<int, vector<int>> adjacencyList;
```

### 图的遍历

##### DFS

``` C++
ret DFS(argument){
    // EXPAND STAGE: visit code: 1. update result. 2. use mem array 3. base case return
    if(flag) return;
    update(res);
    isVisted(root)
    // move forward, neighbours, directions in matrix
    for(auto node : root.neighbours){
        // check state, boundary check, isvisited check
        if(isInBoundary() && ! isVisited(node)){
            // GENERATE STAGE: go to next DFS level, may update the result;
            res += DFS(arguments);
        }
    }
    // we could return;
    return ret;
}

DFS-iterative (G, s):                                   //Where G is graph and s is source vertex
      let S be stack
      S.push( s )            //Inserting s in stack 
      mark s as visited.
      while ( S is not empty):
          //Pop a vertex from stack to visit next
          v  =  S.top( )
         S.pop( )
         //Push all the neighbours of v in stack that are not visited   
        for all neighbours w of v in Graph G:
            if w is not visited :
                     S.push( w )         
                    mark w as visited
```

##### BFS
``` C++
ret BFS(argument){
    // create queue, isGenerated set
    // GENERATE STAGE: push first node to queue and isGenerated set
    queue.push(root);
    isVisited(root);
    while(!queue.empty()){
        // EXPAND STAGE: 1. update result. 2. use mem array. 3. continue or return
        root = queue.front(); queue.pop()
        // move forward, neighbours, directions in matrix
        for(auto node : root.neighbours){
            // check state, boundary check, isvisited check
            if(isInBoundary() && ! isVisited()){
                // GENERATE STAGE: push first node to queue and isGenerated set
                queue.push(root);
                isVisited(root);
            }
        }
    }
    return ret;
}
```
##### BFS+priority_queue 

##### union find

``` C++
 
```