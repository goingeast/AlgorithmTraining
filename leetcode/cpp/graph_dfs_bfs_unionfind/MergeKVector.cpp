
class cmp {
    public:
    bool operator()(const vector<int>::iterator a, const vector<int>::iterator b){
        return (*a) > (*b);
    }
};
vector<int> mergeK(vector<vector<int>>& kArray){
    vector<int> res; 
    priority_queue<vector<int>::iterator, vector<vector<int>::iterator>, cmp) pq;

    for(auto a : kArray){
        if(!a.empty())
            pq.push(a.begin());
    }

    while(!pq.empty()){
        auto iter = pq.top(); pq.pop();

        res.push_back(*iter);
        
        if(++iter)
    }


}