/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s 
and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

Solution: We exclude connected group of 0s on the corners because they are not closed island.
          Then, return number of connected component of 0s on the grid.

CODE:                                                                                                                               */
     int closedIsland(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            if(g[i][0]==0) dfs(g,i,0,n,m);
        }
        for(int i=0;i<n;i++){
            if(g[i][m-1]==0) dfs(g,i,m-1,n,m);
        }
        for(int j=0;j<m;j++){
            if(g[0][j]==0) dfs(g,0,j,n,m);
        }
        for(int j=0;j<m;j++){
            if(g[n-1][j]==0) dfs(g,n-1,j,n,m);
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==0){
                    c++;
                    dfs(g,i,j,n,m);
                }
            }
        }
        return c;
    }
    void dfs(vector<vector<int>>&g,int i,int j,int n,int m){
        if((i>=0&&i<n) && (j>=0&&j<m) && g[i][j]==0){
            g[i][j]=1;
            
            dfs(g,i-1,j,n,m);
            dfs(g,i+1,j,n,m);
            dfs(g,i,j-1,n,m);
            dfs(g,i,j+1,n,m);
        }
    }
