/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Solution: We can go to a cell either from its left cell or its bottom cell.
CODE:                                                                                                                                                          */

     int minPathSum(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        int dp[n][m];
        dp[0][0]=g[0][0];
        for(int i=1;i<m;i++){
            dp[0][i] = dp[0][i-1] + g[0][i];
        }
        for(int i=1;i<n;i++){
            dp[i][0] = dp[i-1][0] + g[i][0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + g[i][j];
            }
        }
        return dp[n-1][m-1];
    }
