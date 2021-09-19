/*
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Input:
grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
Output:
2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 1 0 
There are two islands one is colored in blue 
and other in orange.

Solution: We traverse the grid using DFS, if we encounter any '1' which is unvisited yet, then we increment no. of islands by 1.

CODE:                                                                                                                            */
      int numIslands(vector<vector<char>>& adj) {
        // Code here
        int n=adj.size();
        int m=adj[0].size();
        
        vector<vector<bool>> visited(n);
        for(int i=0;i<n;i++){
            visited[i] = vector<bool>(m,false);
               
        }
        
 
	    int c=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(adj[i][j]=='1' && !visited[i][j]){
	                 c++;
	                 dfs(adj,i,j,visited,n,m);
	            }
	        }
	    }
	    return c;
        
    }
    void dfs( vector<vector<char>>& adj,int x,int y, vector<vector<bool>>& visited,int n,int m){
       
      if((x<n && x>=0) && (y<m && y>=0) && !visited[x][y] && adj[x][y]=='1'){
        visited[x][y]=true;
        
	    dfs(adj,x+1,y,visited,n,m);
	    dfs(adj,x-1,y,visited,n,m);
	    dfs(adj,x+1,y+1,visited,n,m);
	    dfs(adj,x+1,y-1,visited,n,m);
	    dfs(adj,x-1,y+1,visited,n,m);
	    dfs(adj,x-1,y-1,visited,n,m);
	    dfs(adj,x,y+1,visited,n,m);
	    dfs(adj,x,y-1,visited,n,m);
      }
      else
	     return;
    }
