/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Input: matrix = [["1","0","1","0","0"],
                 ["1","0","1","1","1"],
                 ["1","1","1","1","1"],
                 ["1","0","0","1","0"]]
Output: 4

Solution:                                                                                                                                            */
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector< vector<int>>dp(n, vector<int>(m,0));
        int max=0;
      
       // for the 1st row
        for(int i=0;i<n;i++)  {
              if(mat[i][0]=='1') {
                  dp[i][0]=1;
                  max=1;
              }
        }
        
       //for the 1st column
        for(int j=0;j<m;j++)  {
             if(mat[0][j]=='1'){
                 dp[0][j]=1;
                 max=1;
             }  
        } 
       
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]=='1')   dp[i][j] =  min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                
                if(dp[i][j] > max)  max=dp[i][j];
            }
           
        }
        
        return max*max;
    }
