/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Solution: We just have to find the lengest common subsequence, and delete remaining characters from both the strings.

CODE:                                                                                                                          */
    int minDistance(string w1, string w2) {
        int n=w1.length(),m=w2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)    dp[i][0]=0;
        for(int j=0;j<=m;j++)    dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w1[i-1]==w2[j-1])  dp[i][j]=dp[i-1][j-1]+1;
                else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int d=dp[n][m];
      
        return (n+m-2*d);
        
    }
