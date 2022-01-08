/*
Given an array arr[] of integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.
Note: Answer can be very large, so, output answer modulo 10^9+7

Input: 
N = 6, arr[] = {2, 3, 5, 6, 8, 10}
sum = 10

Output: 3

Explanation: {2, 3, 5}, {2, 8}, {10}

Solution:                                                                                                                                              */
	int mod=1000000007;
	int kmp(int arr[], int n, int s, vector<vector<int>>& dp ){
	    if(s==0) return 1;
	    if(n==0) return 0;
	    
	    if(dp[n][s]!=-1)  return dp[n][s];
	    
	    if(arr[n-1]<=s) return dp[n][s]=(kmp(arr,n-1,s-arr[n-1],dp)+kmp(arr,n-1,s,dp))%mod;
	    else return dp[n][s]=kmp(arr,n-1,s,dp)%mod;
	}

	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
       vector<vector<int>>dp(n+1);
       int z=0;
       for(int i=0;i<n;i++) if(arr[i]==0) z++;
       for(int i=0;i<=n;i++) dp[i]=vector<int>(sum+1,-1);
       
       return (kmp(arr,n,sum,dp)+(1 << z)-1)%mod;
	}

