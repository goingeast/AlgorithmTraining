// There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

// Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:

// Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
// Every worker in the paid group must be paid at least their minimum wage expectation.
// Return the least amount of money needed to form a paid group satisfying the above conditions.

 

// Example 1:

// Input: quality = [10,20,5], wage = [70,50,30], K = 2
// Output: 105.00000
// Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
// Example 2:

// Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
// Output: 30.66667
// Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<Worker> workers;
        double ans = DBL_MAX;
        for(int i = 0; i < quality.size(); ++i){
            workers.push_back(Worker(quality[i], wage[i]));
        }
        
        sort(workers.begin(), workers.end());
        
        priority_queue<int> pq;
        int sumq = 0;
        for(auto worker : workers) {
            
            pq.push(worker.getQuality());
            sumq += worker.getQuality();
            
            if(pq.size() > K){
                sumq -= pq.top();
                pq.pop();
            }
            if(pq.size() == K) {
                ans = min(ans, sumq * worker.ratio());
            }
            
        }
        
        return ans;
    }
    
    class Worker{
        public:
        Worker(int quality, int wage){
            mQuality = quality;
            mWage = wage;
        }
        
        double ratio() const{
            return (double) mWage / mQuality;
        }
        
        bool operator< (const Worker& r) const {
            return ratio() < r.ratio();
        }
        
        int getQuality(){
            return mQuality;
        }
        
        int getWage() {
            return mWage;
        }
        private:
            int mQuality;
            int mWage;
    };