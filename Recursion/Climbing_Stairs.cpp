/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Solution:                                                                                                                                                        */
    // 1. Recursive:
    int climbStairs(int n) {
        if(n<=2)  return n;    
        return climbStairs(n-1)+climbStairs(n-2);
    } 
    

    //2. Memoization
    int solve(int n , vector<int>&dp){
        
        if(n<=2)  return dp[n]=n;
        if(dp[n]!=-1)  return dp[n];
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
        
    }
    int climbStairs(int n) {
       vector<int>dp(n+1,-1);
       return  solve(n,dp);
    
    }
