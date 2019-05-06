int minDistance(unordered_map<char,vector<int>>& indexs){
    int s  = indexs.size();
    int result = INT_MAX;
    map<int, pair<char,int>> mp;

    for(auto c : indexs){
        mp[c.second[0]] = {c.first, 0};
    }
    while(mp.size() == s){
        int start = mp.begin()->first;
        int end = prev(mp.end())->first;
        result = min(result, end - start +1);
        //cout << '{' << result << mp.size() <<'}' << endl;
        auto k = mp.begin()->second;
        char word = k.first;
        int index = ++k.second;

        mp.erase(mp.begin());
        if(index < indexs[word].size())
            mp[indexs[word][index]] = {word, index}; 
    }
    return result;
}