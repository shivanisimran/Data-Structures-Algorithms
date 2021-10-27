/*
Given a positive integer N, return the Nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

Example :
1
1 1
1 2 1
1 3 3 1
For N = 3, return 3rd row i.e 1 2 1

Input:
N = 4
Output: 1 3 3 1
Explanation: 4th row of pascal's triangle
is 1 3 3 1.

Solution:        
1. Recursive:                                                                                                                                      */
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<ll>v(n);
        v[0]=1;
        if(n==1) return v;

        for(int i=1;i<n-1;i++){
            v[i]=nthRowOfPascalTriangle(n-1)[i-1]+nthRowOfPascalTriangle(n-1)[i];
        }
        v[n-1]=1;
        return v; 
   }

//2. Tabulation:                                              
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here     
         vector<vector<ll>>dp(n);
         for(int i=0;i<n;i++) dp[i]=vector<ll>(n,0);
         for(int i=0;i<n;i++){
             dp[i][0]=1;
             dp[i][i]=1;
         }
         for(int i=1;i<n;i++){
             for(int j=1;j<n-1;j++) (dp[i][j]=dp[i-1][j-1]+dp[i-1][j])%=1000000007;
         }
         return dp[n-1];
    }
