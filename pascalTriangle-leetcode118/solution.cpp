/*
Question : to return a 2d list/vector of pascal triangle.

solution: use ncr(combination formula), n!/(r!*n-r!).
>> also another formula can be used as 
121,1331,14641,
here we can see eg:1331
2 element(3) 3 = 3/1
3 element(3) 3 = 3*2/1*2
4 element(1) 1 = 3*2*1/1*2*3
using this we know that numerator is decreasing with 1 and numerator is increasing with 1. using this the val can be determined.  
have used x as multiplication of only num or den might exceed the limits of int.


*/

class Solution {
public:
    vector<int> generaterow(int n){
        vector<int> ans ={1};

        if(n==0){
            return ans;
        }
        if(n==1){
            ans.push_back(1);
            return ans;
        }
        int x = n;
        for(int i =1;i<=n;i++){
            ans.push_back(x);
            x = (x*(n-i))/(i+1);
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};