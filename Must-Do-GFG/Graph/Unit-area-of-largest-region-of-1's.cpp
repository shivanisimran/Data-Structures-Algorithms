/*
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).

Input: grid = {{1,1,1,0},{0,0,1,0},{0,0,0,1}}
Output: 5
Explanation: The grid is-
1 1 1 0
0 0 1 0
0 0 0 1

Solution:                                                                                                                        */
int findMaxArea(vector<vector<int>>& g) {
        // Code here
        
        int n=g.size(),m=g[0].size();
        vector<vector<bool>>vis(n);
        for(int i=0;i<n;i++){
            vis[i]=vector<bool>(m,false);
        }
        int m1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1 && !vis[i][j]){
                    int  c=0;
                    dfs(g,i,j,n,m,c,vis);
                    m1=max(c,m1);
                }
            }
        }
        return m1;
    }
    void dfs(vector<vector<int>>& g,int x,int y,int n,int m,int& c,vector<vector<bool>>& vis){
        if((x>=0 && x<n) && (y>=0 && y<m) && !vis[x][y] && g[x][y]==1){
            vis[x][y]=true;
            c++;
            
            dfs(g,x-1,y,n,m,c,vis);
            dfs(g,x+1,y,n,m,c,vis);
            dfs(g,x-1,y-1,n,m,c,vis);
            dfs(g,x-1,y+1,n,m,c,vis);
            dfs(g,x+1,y-1,n,m,c,vis);
            dfs(g,x+1,y+1,n,m,c,vis);
            dfs(g,x,y-1,n,m,c,vis);
            dfs(g,x,y+1,n,m,c,vis);
        }
        else{
            return;
        }      
    }
