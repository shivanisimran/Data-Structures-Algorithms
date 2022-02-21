/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.                               

Solution:                                                                                                                                                                */
// 1. Recursive
    int solve(vector<int>& cost,int n){
        if(n==1)  return cost[0];
        if(n==2) return cost[1];
        
        return min(solve(cost,n-1),solve(cost,n-2))+cost[n-1];
    }
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
       return  min(solve(cost,n),solve(cost,n-1));
        
    }


// 2. Iterative
    int dp[1001];
    int solve(vector<int>& cost,int n){
        if(n==1)  return cost[0];
        if(n==2) return cost[1];
        
        if(dp[n]!=-1)  return dp[n];
        return dp[n]=min(solve(cost,n-1),solve(cost,n-2))+cost[n-1];
    }
    int minCostClimbingStairs(vector<int>& cost) {
    
       int n=cost.size();
       for(int i=0;i<=n;i++)  dp[i]=-1;
       return  min(solve(cost,n),solve(cost,n-1));
        
    }
