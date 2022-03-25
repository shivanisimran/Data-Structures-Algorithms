/*
Given two strings. The task is to find the length of the longest common substring.
Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4. 

Solution:                                                                                                                                              */
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        int dp[n+1][m+1],ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)  dp[i][j]=0;
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    ans=max(ans,dp[i][j]);
                }
                else dp[i][j]=0;
            }
        }
        
        return ans;
        
   }
