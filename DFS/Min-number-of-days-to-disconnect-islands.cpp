/*
Given a 2D grid consisting of 1s (land) and 0s (water).  An island is a maximal 4-directionally (horizontal or vertical) connected group of 1s.
The grid is said to be connected if we have exactly one island, otherwise is said disconnected.
In one day, we are allowed to change any single land cell (1) into a water cell (0).
Return the minimum number of days to disconnect the grid.

Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.

Solution:                                                                                                                          */
   int minDays(vector<vector<int>>&g) {
       int n=g.size(),m=g[0].size();
     
       if(count(g)!=1) return 0; 
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1)  {
                    g[i][j]=0;
                    int x=count(g);
                    g[i][j]=1;
                    if(x!=1)    return 1;
                } 
            }
        }
       return 2;
    }
    
    int count(vector<vector<int>>& g){
        int n=g.size(),m=g[0].size();
        vector<vector<int>>vis(n);
        for(int i=0;i<n;i++) vis[i]=vector<int>(m,0);
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1 && !vis[i][j]) {
                    c++;
                    dfs(g,vis,i,j);
                }   
            }
        }
        return c;
    }
    
    void dfs(vector<vector<int>>& g,vector<vector<int>>&vis,int i,int j){
        int n=g.size(),m=g[0].size();
        if(i>=0 && i<n && j>=0 && j<m && g[i][j]==1 && !vis[i][j]){
            vis[i][j]=1;
            
            dfs(g,vis,i+1,j);
            dfs(g,vis,i-1,j);
            dfs(g,vis,i,j+1);
            dfs(g,vis,i,j-1);
        }
        else return;
    }
