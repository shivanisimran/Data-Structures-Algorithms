/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, 
and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
Determine the perimeter of the island.

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16

Solution:                                                                                                                                  */
    int c=0;
    int islandPerimeter(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
        
        vector< vector<int>>vis(n);
        for(int i=0;i<n;i++){
            vis[i]=vector<int>(m,0);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && g[i][j]){
                    dfs(i,j,vis,g,n,m);
                    break;
                }
            }
        }
        return c;
    }
    void dfs(int x,int y,vector<vector<int>>& vis,vector<vector<int>>&g,int n,int m){
        if((x>=0 && x<n) && (y>=0 && y<m) && !vis[x][y] && g[x][y]){
             vis[x][y]=1;
             c+=4;
             if(x>0 && g[x-1][y])    c--;
             if(x<n-1 && g[x+1][y])    c--;
             if(y>0 && g[x][y-1])    c--;
             if(y<m-1 && g[x][y+1])    c--;
            
            dfs(x+1,y,vis,g,n,m);
            dfs(x-1,y,vis,g,n,m);
             dfs(x,y+1,vis,g,n,m);
             dfs(x,y-1,vis,g,n,m);
        }
       else return;
        
    }
