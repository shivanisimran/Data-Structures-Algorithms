/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Solution:                                                                                                                                        */
    int coinChange(vector<int>& coins, int am) {
        vector<int>dp(am+1,INT_MAX/2);
        dp[0]=0;
        for(int i=0;i<coins.size();i++) if(coins[i]<=am) dp[coins[i]]=1;
        for(int i=1;i<=am;i++){
            for(int j:coins){
                if(i>j) dp[i]=min(dp[i],dp[j]+dp[i-j]);
                
            }
        }
        if(dp[am]==INT_MAX/2)  return -1 ;
        return dp[am];
    }
 
