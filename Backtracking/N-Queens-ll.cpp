/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Solution:                                                                                                                                                      */
    int ans=0;
    int ld[90]={0};
    int rd[90]={0};
    int cl[90]={0};
    
    bool back(vector<string>&q, int j,int n){
        if(j>=n){
          ans++;
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
    
    int totalNQueens(int n) {
        vector<string>q;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++)   s.push_back('.');
            q.push_back(s);
        }
        back(q,0,n);
        return ans;
    }

 
