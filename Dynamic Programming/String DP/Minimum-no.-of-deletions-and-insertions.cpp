/*
Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. 
It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion p and h deleted from heap. Then, p is inserted at the beginning One thing to note, though p was required yet it was 
removed/deleted first from its position and then it is inserted to some other position. Thus, p contributes one to the deletion_count and one to the insertion_count.

Solution: We have to count the characters which are not in the longest common subsequence. If the extra character is in s1, it's needed to be deleted,
          if it's in s2, it is needed to be insertedin s1. So, overall we just have to count the characters in both the strings which are not in LCS.
          
CODE:                                                                                                                                         */

  int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
	    int n=s1.length(),m=s2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)    dp[i][0]=0;
        for(int j=0;j<=m;j++)    dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])  dp[i][j]=dp[i-1][j-1]+1;
                else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int d=dp[n][m];
        
        return (m+n-2*d);
	    
	} 
