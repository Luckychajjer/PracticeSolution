/*
=========================

Question: to find missing and repeating number in an array.

Answer:
>> similar to duplicate number but here we also need to tell the missing number.
>> an array of size n having element (1,n) but one(p) is repeated twice and (q) is missing dins these.
>> repeated one can be founded by fast and slow pointer technique and subracting it from sum of n elements we can 
find the missing number.

Approach 1:
>> using sumation formula:
>> sum of n number is sn=n(n+1)/2, and sum of sqaure of n numbers is sn2 = n(n+1)(2n+1)/6
>> let x be repeating number and y be missing number. 
>> let s be sum of array given and s2 be sum be sqaure of array.
>> then we can say that x-y = s-sn and x2-y2 = s2-sn2
>> then we can evalute x and y to get the value 
*/

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    long long n = a.size();
    long long s=0,s2=0,sn,sn2;
    sn = (n*(n+1))/2;
    sn2 = (n*(n+1)*(2*n+1))/6;
    for(int i=0;i<n;i++){
        s += (long long)a[i];
        s2 += ((long long)a[i]*(long long)a[i]);
    }

    long long c = s-sn; // x-y
    long long b = s2-sn2; // x2-y2
    b = b/c ; //x+y
    long long x = (c+b)/2;
    long long y = x-c;
    return {(int)x,(int)y};
}


/*
optimised:
>> using property of xor (xor of the same number results in zero).
>> first xor all the value in arr and then xor that from(1,n) we will get a value = x^y,
as x would be repeated(thrice) and y only once.
>> then find the first bit of this xor which is 1.eg (2^4 = 6) and the first bit from right to 1 is at pos1(110).
>>then we segreate the value from 1,n based on the bit as pos1, i..e if the bit is 0 as in 1 then it goes to arr0 and 
if the bit is 1 then it goes to arr1.
>>now do the xor of these arr as there will be a number being repeated once or thrice and we found the number but dont know 
if it is missing or repeated.
>> take any of the two value and count its occurance in a and if it is twice then it is repeated and other is missing and vice versa.
*/

vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int xr = 0;
    for (int i=0;i<a.size();i++){
        xr = xr^a[i];
        xr = xr^(i+1);
    }

    //to find the bit
    int bitno=0;
    while(1){
        if((xr && 1<<bitno)!=0){
            break;
        }
        bitno++;
    }
    int a1=0,a0=0;
    for(int i=0;i<a.size();i++){
        if((a[i]&&1<<bitno) !=0 ){
            a1 = a1^ a[i];
        }
        else{
            a0= a0^a[i];
        }
        
        if((i && 1<<bitno) !=0){
            a1= a1^(i+1);
        }else{
            a0 = a0^(i+1);
        }
    }

    int cnt =0;
    for(int i:a){
        if(i==a0) cnt++;
    }
    if(cnt==2) return {a0,a1};
    return {a1,a0};

}
