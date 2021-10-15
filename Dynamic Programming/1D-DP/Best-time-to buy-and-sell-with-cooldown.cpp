/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times)
with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Solution:                                                                                                                                 */
    int maxProfit(vector<int>& p) {
        int n=p.size();
        
        if(n==1)    return 0;
        vector<int>buy(n);
        vector<int>sell(n);
        buy[0]=-p[0];
        sell[0]=0;
        
        buy[1]=max(-p[0],-p[1]);
        sell[1]=max(0,p[1]+buy[1]);
        
        for(int i=2;i<n;i++){
            buy[i]=max(sell[i-2]-p[i],buy[i-1]);
            sell[i]=max(buy[i-1]+p[i],sell[i-1]);
        }
        
        return sell[n-1];
    }
