/*
===============================
Question: to merge the interval if the a value overlaps with other interval.

Solution: 
consider eg [[1,3][2,6][8,12]] >> [[1,6][8,12]]
here 2 can be consider under the same interval as 1,3 so combining both and get the least and max value of interval
>> sort the intial array so that start(0th index value) is definatly smaller than other start element. end(1st index value)
>> check if end value of an index is larger than start value of the next index.if yes, then we have to merge the interval.
update the end value to be maximum of the current index and end value of the next index, start index is already the least due to sort.
>>if end is less than start we can push the start and end to result array.


optimal approach:
>> store the 1 interval and then start cheking the back of vector with the nxt interval.
>> if the end > start of the next interval then update the end value as max of their value.
>> else push the interval and keep checking.

this approach has optimal space complexity of O(n)

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result = {intervals[0]};
        for(int i=0;i<interval.size();i++){
            if(result.back()[1] > intervals[i][0]){
                result.back()[1] = max(result.back()[1],intervals[i][1]);
            }else{
                result.push_back(interval[i]);
            }
        }
        return result;
    }
};