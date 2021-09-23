/*
Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.

Input:
N=3
M=4
A=[[1,0,0,0], 
[1,1,0,1],[0,1,1,1]]
X=2
Y=3 
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).

Solution: The edges are unweighted, so we can do it simply using BFS traversal.

CODE:                                                                                                                    */
int shortestDistance(int n, int m, vector<vector<int>> a, int x, int y) {
        // code here
        queue< pair<int,int> > q;
        
        vector<vector<int>>d(n);
        for(int i=0;i<n;i++){
            d[i] = vector<int>(m,INT_MAX);
               
        }
        if(a[0][0]==1){
            q.push({0,0});
            d[0][0]=0;
        } 
        vector<vector<bool>> vis(n);
        for(int i=0;i<n;i++){
            vis[i] = vector<bool>(m,false);
               
        }
        vis[0][0]=true;
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
           
            q.pop();
            if(i<n-1 &&  a[i+1][j] && !vis[i+1][j]) {
                vis[i+1][j]=true;
              q.push({i+1,j});
                d[i+1][j]=d[i][j]+1;
            }
            if(i>0 && a[i-1][j] && !vis[i-1][j]) { 
                vis[i-1][j]=true;
                q.push({i-1,j});
                d[i-1][j]=d[i][j]+1; 
            }
            if(j>0 && a[i][j-1] && !vis[i][j-1])  {
                vis[i][j-1]=true;
               q.push({i,j-1});
                d[i][j-1]=d[i][j]+1;
            }
            if(j<m-1 && a[i][j+1] && !vis[i][j+1]) { 
                vis[i][j+1]=true;
                q.push({i,j+1});
                d[i][j+1]= d[i][j]+1;
                  
            }
          
        }
        if(d[x][y]==INT_MAX)
            return -1;
        else
            return d[x][y];
    }
