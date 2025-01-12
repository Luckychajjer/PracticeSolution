/*
=========================

Question:sort the value in array withpout sort function and only has 0,1,2.

Solution:
>> use 3 pointer l for 0, r for 2, and i to iterate.
>> we will run the loop till i reaches r as after it(r) would only have 2.
>> if(ith ==0) then swap ith and lth value and increment both value.
>> if(ith ==2) then swap ith and rth value and decrement r.
>> if(ith ==1) then increment i.   

*/

class Solution {
public:
    void sortColor(vector<int>& color) {
        int l =0,r=color.size(),i=0;
        while(i<=r){
            if(color[i]==0){
                swap(color[i],color[l]);
                i++,l++;
            }else if(color[i]==2){
                swap(color[i],color[r]);
                r--;
            }else{
                i++;
            }
        }
    }
};