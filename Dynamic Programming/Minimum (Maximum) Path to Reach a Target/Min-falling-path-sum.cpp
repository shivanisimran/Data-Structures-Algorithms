/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum.

Solution:                                                                                                                                         */
int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==1) return mat[0][0];
        int dp[n][n];
        for(int i=0;i<n;i++)    dp[0][i]=mat[0][i];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++) {
               if(j>0 && j<n-1) dp[i][j]=mat[i][j]+min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]});
               else if(j==0)  dp[i][j]=mat[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
               else if(j==n-1)   dp[i][j]=mat[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            } 
        }
        
        
        int m=INT_MAX;
        for(int i=0;i<n;i++) {
            if(dp[n-1][i]<m) m=dp[n-1][i];
        }
        return m;
}
