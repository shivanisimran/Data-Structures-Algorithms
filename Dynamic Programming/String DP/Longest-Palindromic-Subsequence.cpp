/*
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Solution:                                                                                                                                                  */
   int longestPalindromeSubseq(string s) {
        string t1,t2;
        t1=s;
        reverse(s.begin(),s.end());
        t2=s;
        int n=t1.length();
        int dp[n+1][n+1];
        dp[0][0]=0;
        for(int i=1;i<=n;i++)  dp[i][0]=0;
        for(int j=1;j<=n;j++)  dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){  
                if(t1[i-1]==t2[j-1])    dp[i][j]=dp[i-1][j-1]+1;
                
                else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
                }
            } 
        }
        return dp[n][n];
    }
