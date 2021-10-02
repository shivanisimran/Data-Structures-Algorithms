/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and space is marked as 1 and 0 respectively in the grid.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Solution:                                                                                                                             */
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int n=ob.size(),m=ob[0].size();
        int dp[n][m];
        if(ob[0][0])    dp[0][0]=0;
        else    dp[0][0]=1;
        for(int i=1;i<m;i++){
            if(ob[0][i])    dp[0][i]=0;
            else    dp[0][i]=dp[0][i-1];    
        }    
        for(int i=1;i<n;i++) {
             if(ob[i][0])    dp[i][0]=0;
             else   dp[i][0]=dp[i-1][0];
        }  
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(ob[i][j])   dp[i][j]=0;
                else dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        
        return dp[n-1][m-1];
    }

 
