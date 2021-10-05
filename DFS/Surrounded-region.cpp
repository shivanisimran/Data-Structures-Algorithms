/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. 
             Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. 
             Two cells are connected if they are adjacent cells connected horizontally or vertically.
             
Solution: We run DFS on all boundary 'O' and its neighbour 'O's to exclude them. Then,flip remaining O's to 'X'.   
CODE:                                                                                                                                                    */
     void solve(vector<vector<char>>& b) {
        int n=b.size(),m=b[0].size();
        
        for(int i=0;i<n;i++){
            if(b[i][0]=='O') {
                dfs(b,i,0);
            }  
        }
        for(int i=0;i<n;i++){
            if(b[i][m-1]=='O'){
                   dfs(b,i,m-1);
            }  
        }
         for(int i=0;i<m;i++){
            if(b[0][i]=='O'){
                  dfs(b,0,i);
            }   
        }
         for(int i=0;i<m;i++){
            if(b[n-1][i]=='O')  {
                 dfs(b,n-1,i);
            } 
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]=='1')    b[i][j]='O';
                else if(b[i][j]=='O')   b[i][j]='X';
            }
        }
        
        
    }
    void dfs(vector<vector<char>>&b,int i,int j){
        if((i>=0 && i<b.size()) && (j>=0 && j<b[0].size()) &&  b[i][j]=='O'){
            b[i][j]='1';
            
            dfs(b,i-1,j);
            dfs(b,i+1,j);
            dfs(b,i,j-1);
            dfs(b,i,j+1);
        }
    }

 
