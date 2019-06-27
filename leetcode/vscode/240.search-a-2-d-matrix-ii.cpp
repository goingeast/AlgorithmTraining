/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if( matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int rightUpRow = 0;
        int rightUpCol = matrix[0].size() -1;
        
        while(rightUpRow < matrix.size() && rightUpCol >= 0) {
            if(matrix[rightUpRow][rightUpCol] == target) {
                return true;
            } else if(matrix[rightUpRow][rightUpCol] < target) {
                rightUpRow++;
            } else {
                rightUpCol--;
            }
        }
        
        return false;
    }
};

