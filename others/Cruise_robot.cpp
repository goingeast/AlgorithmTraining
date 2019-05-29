bool isCircle(string path){
    // assume robot face north N, E, S, W
    int dirs[][2] = {{0, 1},{1, 0},{0, -1},{-1, 0}}; 
    int direction = 0;
    pair<int, int> start = {0,0};
    pair<int, int> temp = start;
    for(auto s : path){
        if( s == 'R'){
            direction = (direction + 1) %4;
        }else if( s == 'L'){
            direction = (direction + 3) %4;
        }else{
            temp.first += dirs[direction][0];
            temp.second += dirs[direction][1];
        }
    }

    return start == temp;
}