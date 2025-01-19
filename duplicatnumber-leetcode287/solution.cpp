/*
===================================
Question: there is an array of size n+1 having elements from[1,n] there is atleast one duplicate, have to return that.

Solution: 
>> sort the array and check for recuring i..e, [i]=[i+1] and return that.

optimal
Using linked list cycle, similar to find the start in a linkedlist which can be circular insider.
as number as less than the list size we can move nums[slow].
>> we will keep 2 pointer fast and slow and they move nums[slow] and num[nums[fast]].
>> after they collider or is same, we make fast as nums[0] and move both by one value, nums[slow] and nums[fast].
>> when they meet again is the number being repeated.

*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return nums[i];
            }
        }
        return nums[0];
    }
};


//optimised
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = slow;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};