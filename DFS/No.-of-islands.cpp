/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Solution:                                                                                                                  */
     int numIslands(vector<vector<char>>& g) {
        int n=g.size(),m=g[0].size();
        
        vector< vector<int>>vis(n);
        for(int i=0;i<n;i++){
            vis[i]=vector<int>(m,0);
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && g[i][j]=='1'){
                    c++;
                    dfs(i,j,vis,g,n,m);
                }
            }
        }
        return c;
    }
    void dfs(int x,int y,vector<vector<int>>& vis,vector<vector<char>>&g,int n,int m){
        if((x>=0 && x<n) && (y>=0 && y<m) && !vis[x][y] && g[x][y]=='1'){
             vis[x][y]=1;
             
            dfs(x+1,y,vis,g,n,m);
            dfs(x-1,y,vis,g,n,m);
             dfs(x,y+1,vis,g,n,m);
             dfs(x,y-1,vis,g,n,m);
        }
       else return;
        
    }
