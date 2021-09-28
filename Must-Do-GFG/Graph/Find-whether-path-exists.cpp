/*
Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
The description of cells is as follows:

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Wall.
Note: There are only a single source and a single destination.

Input: grid = {{1,3},{3,2}}
Output: 1
Explanation: The grid is-
1 3
3 2
There is a path from (0,0) i,e source to (1,1) i.e., destination.


Solution: There exists a path if by doing single DFS from source, we can reach destination.
          So, we do DFS traversal from source, and check if destination is visited or not.
          
CODE:                                                                                                          */
    bool is_Possible(vector<vector<int>>& adj) 
    {
        //code here
        int n=adj.size();
        vector<vector<bool>> vis(n);
        for(int i=0;i<n;i++){
            vis[i] = vector<bool>(n,false);
               
        }
        pair<int,int> s,d;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j] == 1) s={i,j};
                else if(adj[i][j]==2)  d={i,j};
            }
        }
        dfs(adj,s.first,s.second,vis,n);
    
        return vis[d.first][d.second];
        
    }
    void dfs(vector<vector<int>>& adj,int x,int y, vector<vector<bool>>& visited,int n){
      if((x<n && x>=0) && (y<n && y>=0) && !visited[x][y] && (adj[x][y]==3||adj[x][y]==1||adj[x][y]==2)){
        visited[x][y]=true;
        
	    dfs(adj,x+1,y,visited,n);
	    dfs(adj,x-1,y,visited,n);
	    dfs(adj,x,y+1,visited,n);
	    dfs(adj,x,y-1,visited,n);
      }
      else
	     return;
   }
