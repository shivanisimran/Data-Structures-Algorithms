/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and space is marked as 1 and 0 respectively in the grid.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Solution:                                                                                                                      */
// Recursion + Memoization
    int solve(vector<vector<int>>& dp,vector<vector<int>>& ob,int n,int m){
        if(dp[n][m]!=-1) return dp[n][m];
        if(m==0 && n==0 ){
           if(ob[0][0])   return dp[n][m]=0;
           else   return dp[n][m]=1; 
        } 
        if(m==0){
            if(ob[n][m])  return dp[n][m]= 0;
            else return dp[n][m]=solve(dp,ob,n-1,m);
        }
        if(n==0){
            if(ob[n][m])   return dp[n][m]= 0;
            else return  dp[n][m]=solve(dp,ob,n,m-1);
        }
        if(ob[n][m])  return dp[n][m]=0;
        else return  dp[n][m]=solve(dp,ob,n-1,m)+solve(dp,ob,n,m-1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int n=ob.size()-1,m=ob[0].size()-1;
       // cout<<n<<" "<<m;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return solve(dp,ob,n,m);
    }
