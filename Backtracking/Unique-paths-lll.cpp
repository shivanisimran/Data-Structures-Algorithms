/*
You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)

Solution:                                                                                                                                           */
    int c=0;
    int uniquePathsIII(vector<vector<int>>& g) {
        int x,y,z=0; 
        int n=g.size(),m=g[0].size();
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    x=i;
                    y=j;
                }
                else if(g[i][j]==0) z++;
                 
            }
        }
        dfs(g,x,y,z,0);
        return c;
        
    }

    void dfs(vector<vector<int>>& g,int i,int j,int z,int k){
        int n=g.size(),m=g[0].size();
        if((i<n && i>=0) && (j<m && j>=0) && g[i][j]!=9){
         
        if(g[i][j]==-1) return;
           
        else if(g[i][j]==2 && k==z+1)  c++;
           
        int t=g[i][j] ;
        g[i][j]=9;
        dfs(g,i+1,j,z,k+1);
        dfs(g,i-1,j,z,k+1);
        dfs(g,i,j+1,z,k+1);
        dfs(g,i,j-1,z,k+1);
        g[i][j]=t;
          
        }
        else
         return;
    }
