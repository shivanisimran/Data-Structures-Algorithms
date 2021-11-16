/*
Nearly everyone has used the Multiplication Table. 
The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.
Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.

Solution:                                                                                                                                        */

//TLE solution:
   int findKthNumber(int m, int n, int k) {
        vector<vector<int>>mat(m);
        for(int i=0;i<m;i++){
            for(int j=1;j<=n;j++) mat[i].push_back((i+1)*j);
        }
        int l=1,r=n*m,ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(countless(mat,mid)>=k){
                ans=mid;
                r=mid-1;
            }
            else    l=mid+1;     
        }
        return ans;
    }
    
    int countless(vector<vector<int>>& mat,int x){
        int n=mat.size(),m=mat[0].size();
        int j=m-1,c=0;
        for(int i=0;i<n;i++){
            while(j>=0 && mat[i][j]>x) j--;
            c+=(j+1);
        }
        return c;
    }
