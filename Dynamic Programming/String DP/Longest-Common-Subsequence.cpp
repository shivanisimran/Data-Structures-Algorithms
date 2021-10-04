/*
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing 
the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.

Solution:                                                                                                                                                  */
   int longestCommonSubsequence(string t1, string t2) {
        int n=t1.length(),m=t2.length();
        int dp[n+1][m+1];
        dp[0][0]=0;
        for(int i=1;i<=n;i++)  dp[i][0]=0;
         for(int j=1;j<=m;j++)  dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){  
                if(t1[i-1]==t2[j-1])    dp[i][j]=dp[i-1][j-1]+1;
                
                else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
                }
            } 
        }
        return dp[n][m];
    }

 
