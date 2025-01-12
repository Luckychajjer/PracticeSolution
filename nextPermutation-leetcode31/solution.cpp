/*
================================================

Question: to find the next permutaion in lexiographical manner(the next greater number).

sol:
eg:2173 >> ans: 2317

Approach:
>> find the peak from start i..e when is arr[i]<arr[i+1]
>> from eg i =1. then from end(3) check till (1). to find a number just greater than arr[i], for closest next number.
>> and swap then here 3<->1(arr[3]<->arr[1]). and sort the rest from i+1 to end.
>> if no peak is found return the ascending order.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind =-1;
        for(int r =0;r<nums.size()-1;r++){
            if(nums[r]<nums[r+1]){
                ind = r;
            }
        }        
        if(ind!=-1){
            for(int i=nums.size()-1;i>ind;i--){
                if(nums[i]>nums[ind]){
                    int x = nums[i];
                    nums[i] = nums[ind];
                    nums[ind] = x;
                    break;
                }
            }
            sort(nums.begin()+ind+1,nums.end());
        }else{
            sort(nums.begin(),nums.end());
        }

    }
};