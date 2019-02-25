// Next Closest Time
// Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.

// You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.

// Example 1:

// Input: "19:34"
// Output: "19:39"
// Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  
// It is not 19:33, because this occurs 23 hours and 59 minutes later.

// Example 2:

// Input: "23:59"
// Output: "22:22"
// Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. 
// It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.

class Solution {
public:
    /**
     * @param time: the given time
     * @return: the next closest time
     */
    string nextClosestTime(string &time) {
        // write your code here
        unordered_set<int> digits;
        for(char c : time) {
            if(isdigit(c))
                digits.insert(c - '0');
        }
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3));
        int basetime = toMins(hour, min);
        int best = basetime;
        vector<int> currentTime(4, 0);
        // convert to mins
        nextClosestTime(0, digits, currentTime, basetime, best);
        char buffer[5];
        sprintf(buffer, "%02d:%02d", best/60, best%60);
        return string(buffer);
        
        
    }
    
    void nextClosestTime(int depth, unordered_set<int>& digits, vector<int>& currentTime, int basetime, int& best) {
        if(depth == 4){
            
            int hh = currentTime[0]*10 + currentTime[1];
            int mm = currentTime[2]*10 + currentTime[3];
            
            if(hh < 24 && mm < 60){
                int localTime = toMins(hh, mm);
                if(diff(basetime, localTime) < diff(basetime, best)){
                    best = localTime;
                }
            }
            return;
        }
        
        for(auto digit : digits){
            currentTime[depth] = digit;
            
            nextClosestTime(depth+1, digits, currentTime, basetime, best);
        }
        
    }
    
    int toMins(int hh, int mm){
        return hh * 60 + mm;
    }
    
    int diff(int t1, int t2) {
        if(t1 == t2) return INT_MAX;
        return (t2 - t1 + 24*60)%(24*60);
    }
};