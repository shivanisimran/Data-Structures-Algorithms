/*
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. 
For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.

Solution:                                                                                                                                              */
      int n;
	    string s1, s2;
	    int dp[1001][1001];
	    
	    int lcs(int i,int j){
	        if(i<0 || j<0)  return 0;
	        
	        if(dp[i][j]!=-1)  return dp[i][j];
	        
	        if(s1[i]==s2[j] && i!=j)  return dp[i][j]=lcs(i-1,j-1)+1;
	        return dp[i][j] = max(lcs(i,j-1),lcs(i-1,j));
	    }
	    
		 int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    n=str.size();
		    s1=str;
		    s2=str;
		    memset(dp,-1,sizeof dp);
		    
		    return lcs(n,n);
		    
		 }
