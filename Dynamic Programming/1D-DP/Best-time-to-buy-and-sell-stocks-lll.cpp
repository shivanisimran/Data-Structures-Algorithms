/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Solution:                                                                                                                                                */
    int maxProfit(vector<int>& prices) {
        int buy1=INT_MIN,buy2=INT_MIN,sell1=0,sell2=0;
        for(auto p:prices){
            buy1=max(buy1,-p);
            sell1=max(sell1,buy1+p);
            buy2=max(buy2,sell1-p);
            sell2=max(sell2,p+buy2);
        }
        return sell2;
    }
