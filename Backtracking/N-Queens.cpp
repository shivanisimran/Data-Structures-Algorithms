/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

Solution:                                                                                                                                          */
    vector<vector<string>>ans;
    int ld[90]={0};
    int rd[90]={0};
    int cl[90]={0};
    int r[90]={0};
    
    bool back(vector<string>&q, int j,int n){
        if(j>=n){
          vector<string>v;
          for(int i=0;i<n;i++)  v.push_back(q[i]);
          ans.push_back(v);
          return true;  
        } 
        for(int i=0;i<n;i++){
            if(!ld[i+j] && !rd[i-j+20] && !cl[i]){
                q[i][j]='Q';
                ld[i+j]=1;
                rd[i-j+20]=1;
                cl[i]=1;
                
                back(q,j+1,n);
                
                
                q[i][j]='.';
                ld[i+j]=0;
                rd[i-j+20]=0;
                cl[i]=0;
                
            }
           
        }
        return false;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>q;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++)   s.push_back('.');
            q.push_back(s);
        }
        back(q,0,n);
        return ans;
    }

