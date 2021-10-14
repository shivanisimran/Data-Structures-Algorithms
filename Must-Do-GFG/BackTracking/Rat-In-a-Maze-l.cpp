/*
Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
Find all possible paths in lexographical order that the rat can take to reach from source to destination. 
The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR

Solution:                                                                                                                                           */
    vector<string> ans;
    vector<string> findPath(vector<vector<int>>&m, int n) {
        // Your code goes here
        vector<vector<int>>vis(n);
        for(int i=0;i<n;i++)
            vis[i]=vector<int>(n,0);
        dfs(m,n,0,0,"",vis);
        sort(ans.begin(),ans.end());
        return ans;
        
    }

    void dfs(vector<vector<int>>&m,int n,int x,int y,string str,vector<vector<int>>vis){
        if(x>=0 && x<n && y>=0 && y<n && !vis[x][y] && m[x][y]==1){
            if(x==n-1 && y==n-1){
                ans.push_back(str);
                return;
            }
            vis[x][y]=1;
            if(x>0 && m[x-1][y]!=0 && !vis[x-1][y]){
                str+='U';
                dfs(m,n,x-1,y,str,vis);
                str.pop_back();
            }
            if(y>0 && m[x][y-1]!=0 && !vis[x][y-1]){
                str+='L';
                dfs(m,n,x,y-1,str,vis);
                str.pop_back();
            }
            if(x<n-1 && m[x+1][y]!=0 && !vis[x+1][y]){
                str+='D';
                dfs(m,n,x+1,y,str,vis);
                str.pop_back();
            }
            if(y<n-1 && m[x][y+1]!=0 && !vis[x][y+1]){
                str+='R';
                dfs(m,n,x,y+1,str,vis);
                str.pop_back();
            }
        }
        
         
    }
