/*
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. 
Output your answer modulo 10^9 + 7.

Input:
N = 3
Output: 5
Explanation: 5 strings are (000,
001, 010, 100, 101). 

Solution: 
It is similar to painting stairs problem (Given n stairs and we have 2 colour yellow and green. 
  The task is that we have to paint given stairs by given colour
  with condition is that we cannot paints two yellow steps directly after each other.)
  It follows Fibonacci Series.
*/

ll countStrings(int n) {
	    // code here
	    int dp[n+1];
	    dp[0]=0;
	    dp[1]=2;
	    dp[2]=3;
	    for(int i=3;i<=n;i++){
	        dp[i]=(dp[i-1]+dp[i-2])%1000000007;
	    }
	    return dp[n];
	}
