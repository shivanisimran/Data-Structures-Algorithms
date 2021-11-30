/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Solution:                                                                                                                                                       */
    int vis[501][501]={0};
    void dfs(int x,int y,vector<vector<int>>& g){
        int n=g.size(),m=g[0].size();
        if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && g[x][y]==1){
            vis[x][y]=1;
            g[x][y]=0;
            
            dfs(x+1,y,g);
            dfs(x-1,y,g);
            dfs(x,y+1,g);
            dfs(x,y-1,g);
        }
    }
    
    int numEnclaves(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(!vis[i][j])  dfs(i,j,g);
                }
            }
        }
        
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(g[i][j]==1)   c++;
            }
        }
        
       return c; 
    }
