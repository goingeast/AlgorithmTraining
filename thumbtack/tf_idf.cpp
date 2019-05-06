class TFIDF{
public:
    void preprocess(vector<vector<string>>& docs){
        totalDocsNumber = docs.size();
        for(int i = 0; i < docs.size(); ++i){
            unordered_map<string, int> wordCount;
            
            for(int j = 0; j < docs[i].size(); ++j) {
                if(wordCount.find(docs[i][j]) == wordCount.end()) {
                    wordOccurence[docs[i][j]]++;
                }
                wordCount[docs[i][j]]++;
            }
            wordCounts.push_back(wordCount);
            docSize.push_back(docs[i].size());
        }

        for(auto d : docSize) cout << d << ',';
        cout << endl;
        int i = 0;
        for(auto d : wordCounts) {
            cout << i++; 
            for(auto t : d){
                cout << '{' << t.first << ',' << t.second <<'}';
            }
            cout << endl;
        }

        for(auto d : wordOccurence){
            cout << '{' << d.first << d.second << '}';
        }
        cout << endl;
    }

    vector<int> topK(vector<string>& querys, int k){

        priority_queue<pair<double, int>> tfidfs;

        for(int i = 0; i < totalDocsNumber; ++i){
            pair<double, int> doctfidf{0.0, i};

            for(auto query:querys){
                double tf = 0.0;
                if(wordCounts[i].count(query) != 0) {
                    tf = wordCounts[i][query] / (double)docSize[i];
                }
                double idf = 0.0;
                if(wordOccurence.count(query) != 0) {
                    idf = log((totalDocsNumber)/(double)(wordOccurence[query]));
                }
                cout << '{' << tf  << ','<< idf << '}';
                doctfidf.first += tf * idf;
            }
            cout << endl;
            cout << doctfidf.first << endl;
            tfidfs.push(doctfidf);
            while(tfidfs.size() > k){
                tfidfs.pop();
            }
        }
        int end = tfidfs.size();
        vector<int> ans(end, 0.0);

        while(!tfidfs.empty()){
            ans[--end] = tfidfs.top().second; 
            tfidfs.pop();
        }
        return ans;
    }

    int sumOfDiv(int x)
    {
        // 1 is a proper divisor
        int sum = 1;
        for(int i = 2; i <= sqrt(x); i++)
        {
            if(x % i == 0)
            {
                sum += i;
                if( x / i != i){
                    sum += x /i;
                } 
            }
        }
        return sum;
    }

private:
    int totalDocsNumber;
    vector<int> docSize;
    vector<unordered_map<string, int>> wordCounts;
    unordered_map<string, int> wordOccurence;
};


// tf = word_cout/ all_word_in_doc
// idf = log(total_doc_count/a_word_occurance_doc_count)