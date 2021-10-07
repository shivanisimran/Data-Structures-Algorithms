/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Solution:                                                                                                                                       */
    bool exist(vector<vector<char>>& b, string w) {
        int n=b.size(),m=b[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(dfs(i,j,b,w,n,m,0)) return true;
            }
            
        }
        return false;
        
    }
    bool dfs(int i,int j,vector<vector<char>>& b,string w,int n,int m,int x){
           
            if((i<0 || i>=n) || (j<0 || j>=m) || b[i][j]!=w[x])  return false;
            if(x==w.length()-1)   return true;
            
            char c=b[i][j];
            b[i][j]='*';
            bool ans= dfs(i+1,j,b,w,n,m,x+1)||
            dfs(i-1,j,b,w,n,m,x+1)||
            dfs(i,j+1,b,w,n,m,x+1)||
            dfs(i,j-1,b,w,n,m,x+1);
        
            b[i][j]=c;
            return ans;
     
    }
