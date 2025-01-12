/*
============================
question:
Given an integer array nums, find the subarray with the largest sum, and return its sum.

sol: also called kadane's Algo
>>let ans be arr[0].
>>if the sum is -ve then make it zero and continue by adding the next position.
>>keep the maximum ans as max(ans, sum).

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        for(auto i:nums){
            if(sum <0){
                sum =0;
            }
            sum +=i;
            ans = sum>ans? sum :ans;
        }
        return ans
    }
};