/*
Given an integer n, return the least number of perfect square numbers that sum to n.
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4. */

int numSquares(int n) {
        int dp[n+1]; // we use dp array to store ans for all numbers from zero to n.
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int m=INT_MAX;
            for(int j=1;j*j<=i;j++){ // traversing all perfect sqares from 1 to 'i'
                int rem = i-j*j; // remaining value
                if(dp[rem]<m)   
                    m=dp[rem];  //we will choose that value fo rem for whilch dp[rem] is least.
            }
            dp[i]=m+1; // it will be answer for 'i'.
        }
        return dp[n];
    }
