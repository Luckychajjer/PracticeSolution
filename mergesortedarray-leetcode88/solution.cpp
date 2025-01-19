/*
==========================
Question: to merge 2 sorted array.

solution: 
2 array are given and we cant return the final array and 1st array is of size(m+n), and to do it without extra space.

intead of doing it in ascending order , start in descending order.
>> let i be m-1 for arr1 and j be n-1 for arr2 and keep a third pointer to write the value = m+n in arr1.
>> if the arr1[i] > arr2[j] then store arr1[i] to arr1[r] and decrement both values.
>> else do the opposite for arr2 , do this till one of array index(i or j) reaches -1.
>> after that add the rest of element of the remaining array.

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,r = m+n-1;
        while( i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                nums1[r] = nums1[i];
                i--,r--;
            }else{
                nums1[r] = nums2[j];
                j--,r--;
            }
        }
        while(i>=0){
            nums1[r] = nums1[i];
            i--,r--;
        }
        while(j>=0){
            nums1[r] = nums2[j]
            j--,r--;
        }
    }
};