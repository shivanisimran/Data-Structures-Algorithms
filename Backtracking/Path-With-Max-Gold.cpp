/*
In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.

Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
Output: 24
Explanation:
[[0,6,0],
 [5,8,7],
 [0,9,0]]
Path to get the maximum gold, 9 -> 8 -> 7.

Solution:                                                                                                                                              */
   int getMaximumGold(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size(),z=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                z=max(z,dfs(g,i,j));
            }
        }
        return z;
    }

    int dfs(vector<vector<int>>& g,int x,int y){
         int n=g.size(),m=g[0].size();
         if(x>=0 && x<n && y>=0 && y<m && g[x][y]>0){
             
            g[x][y]=-g[x][y];
             
            int res=max({dfs(g,x+1,y),
            dfs(g,x-1,y),
            dfs(g,x,y+1),
            dfs(g,x,y-1)});
            
            g[x][y]=-g[x][y];
           
            return res+g[x][y];
        }
       else return 0;
        
    }
