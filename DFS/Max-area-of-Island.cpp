/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) 
You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],
              [0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Solution:                                                                                                                                */
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        
        vector< vector<int>>vis(n);
        for(int i=0;i<n;i++){
            vis[i]=vector<int>(m,0);
        }
        int m1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && g[i][j]){
                    int c=0;
                    dfs(i,j,vis,g,n,m,c);
                    m1=max(m1,c);
                }
            }
        }
        return m1;
    }
    void dfs(int x,int y,vector<vector<int>>& vis,vector<vector<int>>&g,int n,int m,int& c){
        if((x>=0 && x<n) && (y>=0 && y<m) && !vis[x][y] && g[x][y]){
             vis[x][y]=1;
             c++;
            
            dfs(x+1,y,vis,g,n,m,c);
            dfs(x-1,y,vis,g,n,m,c);
             dfs(x,y+1,vis,g,n,m,c);
             dfs(x,y-1,vis,g,n,m,c);
        }
       else return;
        
    }

 
