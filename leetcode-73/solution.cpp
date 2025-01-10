/*
======================
Question:   
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

Approach:
Create a vector of pair which stores postion of the zeroes in the matrix.
After getting postion of zero, make all the respective row and col to 0.  
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> ind;
        int height = matrix.size();
        int width = matrix[0].size();
        for(int i =0;i<height;i++){
            for(int j =0;j<width;j++){
                if(matrix[i][j]==0){
                    ind.push_back({i,j});
                }
            }
        }
        for(auto j : ind){
            for(int i =0;i<width;i++){
                matrix[j.first][i]=0;
            }
            for(int i =0;i<height;i++){
                matrix[i][j.second]=0;
            }
        }
    }
};