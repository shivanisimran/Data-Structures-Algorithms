/*
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.

Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.

Solution:

DFS:                                                                                                                                                  */
    int dfs(vector<vector<int>>& g,int r,int c1,int c2){
        int n=g.size(),m=g[0].size();
        int ans=0;
        if(r>=0 && r<n && c1>=0 && c1<m && c2>=0 && c2<m){
            
            if(c1!=c2) ans+=g[r][c1]+g[r][c2];
            else ans+=g[r][c1];
            
            int a=0;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    a=max(a,dfs(g,r+1,c1+i,c2+j));
                }
            } 
            ans+=a;
            return ans;
        }
        
        else return 0;
       
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        return dfs(grid,0,0,m-1);
    }


//DFS + Memoization (to avoid TLE)
    int dp[71][71][71];
    int dfs(vector<vector<int>>& g,int r,int c1,int c2){
        int n=g.size(),m=g[0].size();
        int ans=0;
        
        if(r>=0 && r<n && c1>=0 && c1<m && c2>=0 && c2<m){
            
            if(dp[r][c1][c2] != -1)  return dp[r][c1][c2];
            if(c1!=c2) ans+=g[r][c1]+g[r][c2];
            else ans+=g[r][c1];
            
            int a=0;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    a=max(a,dfs(g,r+1,c1+i,c2+j));
                }
            } 
            ans+=a;
            return dp[r][c1][c2] = ans;
        }
        
        else return 0;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        return dfs(grid,0,0,m-1);
    }
