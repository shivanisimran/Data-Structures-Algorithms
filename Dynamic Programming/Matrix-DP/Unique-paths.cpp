/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Solution:                                           

CODE:                                                                                                                               */
   int uniquePaths(int m, int n) {
        int dp[m][n];
        dp[0][0]=1;
        for(int i=1;i<n;i++)    dp[0][i]=dp[0][i-1];
        
        for(int j=1;j<m;j++)    dp[j][0]=dp[j-1][0];
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
