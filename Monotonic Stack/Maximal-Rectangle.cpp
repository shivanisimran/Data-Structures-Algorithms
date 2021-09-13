/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6

Solution:  For each row, we have to make histogram. Height of histogram at each column would be no. of consecutive ones including current row and upper rows.
           Then, we will find maximum area under histogram for each row, and return the one which is maximum.
           
CODE:                                                                                                                         */

    //function for finding maximum area under histogram.
     int larea(vector<int>& ht){
        int n=ht.size();
        vector<int> l;
        vector<int> r;
        for(int i=0;i<n;i++){
            l.push_back(i);
            r.push_back(n-i-1);
        }
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && ht[st.top()]>ht[i]){
                r[st.top()]=i-st.top()-1;
                st.pop();
            }
            st.push(i);     
        }
        stack<int> s1;
        for(int i=n-1;i>=0;i--){
            while(!s1.empty() && ht[s1.top()]>ht[i]){
                l[s1.top()]=s1.top()-i-1;
                s1.pop();
            }
            s1.push(i);  
        }
        int x=0;
        for(int i=0;i<n;i++){
            x=max(x, (ht[i]*(l[i]+r[i]+1)));
        } 
        return x;
    }
    
   //function for maximal rectangle.
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=0;
        vector<vector<int>> mat(matrix.size());
      
        for(int i=0;i<matrix.size();i++){
            mat[i]=vector<int>(matrix[i].size());
            for(int j=0;j<matrix[i].size();j++){
                mat[i][j]=(matrix[i][j]-48);
            }
        }
      
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1')
                    mat[i][j]+=mat[i-1][j];
            }
        }
      
        for(int i=0;i<matrix.size();i++){
            m=max(m,larea(mat[i]));
        }
        return m;
    }
