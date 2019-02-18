// Given a robot cleaner in a room modeled as a grid.

// Each cell in the grid can be empty or blocked.

// The robot cleaner with 4 given APIs can move forward, turn left or turn right. Each turn it made is 90 degrees.

// When it tries to move into a blocked cell, its bumper sensor detects the obstacle and it stays on the current cell.

// Design an algorithm to clean the entire room using only the 4 given APIs shown below.

// interface Robot {
//   // returns true if next cell is open and robot moves into the cell.
//   // returns false if next cell is obstacle and robot stays on the current cell.
//   boolean move();

//   // Robot will stay on the same cell after calling turnLeft/turnRight.
//   // Each turn will be 90 degrees.
//   void turnLeft();
//   void turnRight();

//   // Clean the current cell.
//   void clean();
// }
// Example:

// Input:
// room = [
//   [1,1,1,1,1,0,1,1],
//   [1,1,1,1,1,0,1,1],
//   [1,0,1,1,1,1,1,1],
//   [0,0,0,1,0,0,0,0],
//   [1,1,1,1,1,1,1,1]
// ],
// row = 1,
// col = 3

// Explanation:
// All grids in the room are marked by either 0 or 1.
// 0 means the cell is blocked, while 1 means the cell is accessible.
// The robot initially starts at the position of row=1, col=3.
// From the top left corner, its position is one row below and three columns right.
// Notes:

// The input is only given to initialize the room and the robot's position internally. You must solve this problem "blindfolded". In other words, you must control the robot using only the mentioned 4 APIs, without knowing the room layout and the initial robot's position.
// The robot's initial position will always be in an accessible cell.
// The initial direction of the robot will be facing up.
// All accessible cells are connected, which means the all cells marked as 1 will be accessible by the robot.
// Assume all four edges of the grid are all surrounded by wall.


class Solution {
public:
    
    void cleanRoom(Robot& robot) {
        unordered_set<size_t> visited;
        helper(robot, 0, 0, 0, visited);
    }
    void helper(Robot& robot, int x, int y, int dir, unordered_set<string>& visited) {
        robot.clean();
        visited.insert(key(x, y));
        
        vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0; i < dirs.size(); ++i) {
            int cur = (i + dir) % 4; // get next direction when turn right
            int newX = x + dirs[cur][0];
            int newY = y + dirs[cur][1];

            if (!visited.count(key(newX, newY)) && robot.move()) {
                helper(robot, newX, newY, cur, visited);
                robot.turnRight(); // get back
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
        }
    }

    size_t key(size_t i, size_t j){
        return i << 32 | j;
    }
};