/*
=============================
Question : to rotate nxn array by 90degree clk.

Solution:
>> this involves in reversing the array and then exchanging.
>> reverse the array in 2d as if 3 rows the swap(row1, row3).
>> then swap element with its mirror as(a[i][j], a[j][i]), but remeber not to do it for whole as then it would redo work on element 
eg a[1][2], a[2][1] this would be called on 1,2 once and again when crossing 2,1so skip the secong time, by reducing the number of 
to swap by one after each row.
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size()-1,i=0;
        while(i<size){
            swap(matrix[i],matrix[size]);
        }
        for (int i = 0; i < matrix.size(); i++){
            for (int j = i; j < matrix[0].size(); j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};