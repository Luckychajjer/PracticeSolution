/*
======================================
Question: to find the number of occurance where arr[i] > arr[j] but i<j;

solution:
>> we can run a nested for loop and compare if arr[i] is greater than elements from i+1,n and increment count.
>> this take n2 time complexity.

Optimal:
>> using merge sort technique to get it to nlogn time.
>> do a normal merge sort but while merging them back if the left element is greater than its right we add 
to the count the number of element left in left array, as if the ith element is greater than it then as it is sorted
the elements after it will also be greater than it.
*/
vector<long long> merge(vector<long long> left,vector<long long> right,long long &cnt){
    vector<long long> ans;
    int i =0,j=0;
    while(i<left.size() && j<right.size()){
      if (left[i] > right[j]) {
        ans.push_back(right[j]);
        cnt = cnt + (left.size()-i);
        j++;
      }else{
        ans.push_back(left[i]);
        i++;
      }
    }
    while(i<left.size()){
        ans.push_back(left[i]);
        i++;
    }
    while(j<right.size()){
        ans.push_back(right[j]);
        j++;
    }
    return ans;
}

vector<long long> mergesort(vector<long long> arr,int size,long long &cnt){
  if(size==1) return arr;
  int mid = ceil(size/2);
  vector<long long> ans;
  vector<long long> leftarr(arr.begin(),arr.begin()+mid);
  vector<long long> rightarr(arr.begin()+mid,arr.begin()+size);

  leftarr = mergesort(leftarr,mid,cnt);
  rightarr = mergesort(rightarr,size-mid,cnt);

  ans = merge(leftarr,rightarr,cnt);
  return ans;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    long long cnt=0;
    vector<long long> arr1(arr,arr+n);
    mergesort(arr1,n,cnt);
    return cnt;
}