/*
Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Solution:                                                                                                               */
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(),m=s2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)    dp[i][0]=0;
        for(int j=0;j<=m;j++)    dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])  dp[i][j]=dp[i-1][j-1]+s1[i-1];
                else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int d=dp[n][m];
        int s=0;
        for(int i=0;i<n;i++) s+=s1[i];
        for(int j=0;j<m;j++) s+=s2[j];
        return (s-2*d);
    }
