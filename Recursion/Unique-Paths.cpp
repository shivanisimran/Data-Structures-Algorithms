/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Solution:                                                                                                                       */
    //Recursive
    int uniquePaths(int m, int n) {
        if(m==1 || n==1)  return 1;

        return uniquePaths(m,n-1)+uniquePaths(m-1,n);
        
    } 
    
    //Memoised
    int solve(vector<vector<int>>& dp,int m,int n){
        if(m==1 || n==1)  return dp[m][n]=1;
        
        if(dp[m][n]!=-1)  return dp[m][n];
        
        return dp[m][n] = solve(dp,m,n-1)+solve(dp,m-1,n);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1);
        for(int i=0;i<=m;i++)  dp[i]=vector<int>(n+1,-1);
        
        return solve(dp,m,n);
    }
