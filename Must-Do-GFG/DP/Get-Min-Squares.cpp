/*
Given a number N. Find the minimum number of squares of any number that sums to N. 
For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).

Input: N = 100
Output: 1
Explanation: 10 * 10 = 100

Solution:                                                                                                                                                            */
  int dp[10004];
	int fun(int n){
	    if(n<=0)  return 0;
	    
	    if(dp[n]!=-1)  return dp[n];
	    
	    int m=INT_MAX;
	    for(int i=1;i*i<=n;i++){
	        m=min(m,fun(n - i*i)+1);
	    }
	    
	    return dp[n]=m;
	    
	}
	
	int MinSquares(int n)
	{
	    // Code here
	    memset(dp,-1,sizeof dp);
	    return fun(n);
	    
	}
