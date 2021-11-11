/*
Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.

Solution:                                                                                                                               */
int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==1) return mat[0][0];
        int dp[n][n];
        for(int i=0;i<n;i++)    dp[0][i]=mat[0][i];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++) {
                int m=INT_MAX;
                for(int k=0;k<j;k++) if(m>dp[i-1][k]) m=dp[i-1][k];
                for(int k=j+1;k<n;k++) if(m>dp[i-1][k]) m=dp[i-1][k];
                
                dp[i][j]=mat[i][j]+m;
            } 
        }
        
        
        int m=INT_MAX;
        for(int i=0;i<n;i++) {
            if(dp[n-1][i]<m) m=dp[n-1][i];
        }
        return m;
}
