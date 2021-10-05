/*
You are given an m x n integer matrix grid, and three integers row, col, and color. Each value in the grid represents the color of the grid square at that location.
Two squares belong to the same connected component if they have the same color and are next to each other in any of the 4 directions.

The border of a connected component is all the squares in the connected component that are either 4-directionally adjacent to a square 
not in the component, or on the boundary of the grid (the first or last row or column).

You should color the border of the connected component that contains the square grid[row][col] with color.
Return the final grid.

Solution:                                                                                                                                  */
    vector<vector<int>> colorBorder(vector<vector<int>>& g, int r, int c, int col) {
        int x=g[r][c];
        int n=g.size(),m=g[0].size();
        vector<vector<int>>vis(n);
        for(int i=0;i<n;i++)    vis[i]=vector<int>(m,0);
        dfs(g,vis,r,c,col,x,n,m);
        return g;
    }
    void dfs(vector<vector<int>>&g,vector<vector<int>>&vis, int r, int c, int col,int x,int n,int m){
        if((r>=0&&r<n) && (c>=0&&c<m) && g[r][c]==x && !vis[r][c]){
            vis[r][c]=1;
            if(r==0 || r==n-1 || c==0 || c==m-1)    g[r][c]=col;
            if(r>0 && g[r-1][c]!=x && !vis[r-1][c])   g[r][c]=col;
            if(r<n-1 && g[r+1][c]!=x && !vis[r+1][c])   g[r][c]=col;
            if(c>0 && g[r][c-1]!=x && !vis[r][c-1])   g[r][c]=col;
            if(c<m-1 && g[r][c+1]!=x && !vis[r][c+1])   g[r][c]=col;
            
            dfs(g,vis,r-1,c,col,x,n,m);
            dfs(g,vis,r+1,c,col,x,n,m);
            dfs(g,vis,r,c-1,col,x,n,m);
            dfs(g,vis,r,c+1,col,x,n,m);
        }
    }
