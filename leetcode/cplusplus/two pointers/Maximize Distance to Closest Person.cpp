// n a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

// There is at least one empty seat, and at least one person sitting.

// Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

// Return that maximum distance to closest person.

// Example 1:

// Input: [1,0,0,0,1,0,1]
// Output: 2
// Explanation: 
// If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
// If Alex sits in any other open seat, the closest person has distance 1.
// Thus, the maximum distance to the closest person is 2.
// Example 2:

// Input: [1,0,0,0]
// Output: 3
// Explanation: 
// If Alex sits in the last seat, the closest person is 3 seats away.
// This is the maximum distance possible, so the answer is 3.

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        if(seats.empty()) return -1;
        int left = -1, right = -1;
        int len = seats.size();
        int dist = 0;

        int i = 0;
        while(i < len) {
            // while 1 
            while (i < len && seats[i] == 1) {
                i++;
            }
            left = i;
            //while 0
            while(i < len && seats[i] == 0) {
                i++;
            }
            right = i;
            // if start index 0 or end last,dist is (right - left)
            // or dist is Math.ceil((right - left) / 2.0)
            if(left == 0 || right == len) {
                dist = max(right - left, dist);
            } else {
                dist = max((right - left+1) / 2, dist);
            }
        }
        return dist;
    }
};