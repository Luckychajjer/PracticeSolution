/*
============================

Question: Find the optimal day to buy and sell stock for maximum profits.

Solution: 
return 0 if -ve profit.
>> go throght each iteration, if the number is lower update the buy value.
>> else, find the profit if sold that day and keep the max profit by comparing with previous value.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],profit=0;
        for(int i:prices){
            if(buy<i){
                profit = max(profit,(i-profit));
            }else{
                buy =i;
            }
        }
        return profit;
    }
};