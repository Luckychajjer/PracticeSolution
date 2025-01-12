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



/*
===========================================
Optimal Approach
using it in a way of hash map,
>> if a 0 is found in then we mark the respective 0th row and col as 0 as a way to remember, but 0,0 would be used twice
so we use a variable col0.
>> first we traverse the matrix and see and if eg:0 is found at (1,2) then respective (0,2) and (1,0) is marked as 0.
>> if (0,0) is 0 then col0 is 0, and 0,0, is also 0.
>> after traversing we start travering again to fill in the zeros based on hash map, but do not include first roiw and column(0th).
>>start from 1,1 and check if its respective any row or column is zero then make it zero, this will make all the places with 0 required to zero.
>> for oth row and coloumn mast of the changes would have been made except for cases as in if there is a 0 at (0,0) and no where else,
so we add if col0 then made the whole col 0(0,[..]) to 0 or vice versa for row.  

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // col[n] = {0} matrix[0][..]
        // row[n] = {0} matrix[..][0]
        int col0=1;
        for(int i =0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0] =0;

                    if(j!=0){
                        matrix[0][j]=0;
                    }else{
                        col0 =0;
                    }
                }
            }
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] =0;
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int i=0;i<matrix[0].size();i++) matrix[0][i] =0;
        }
        if(col0 ==0){
            for(int i=0;i<matrix.size();i++) matrix[i][0] =0;
        }
    }
};