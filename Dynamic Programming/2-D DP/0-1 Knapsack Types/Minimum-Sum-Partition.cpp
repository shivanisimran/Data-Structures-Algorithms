/*
Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that 
the absolute difference between their sums is minimum and find the minimum difference

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   

Solution:                                                                                                                                             */
   vector<vector<int>>dp;
   int knp(int arr[],int n,int t){
        if(dp[n][t]!=-1) return dp[n][t];
        if(n==0 || t==0) return 0;
        
       
        if(arr[n-1]<=t)  return dp[n][t]=max(arr[n-1]+knp(arr,n-1,t-arr[n-1]),knp(arr,n-1,t));
        else return dp[n][t]=knp(arr,n-1,t);
   }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int s=0;
	    for(int i=0;i<n;i++)  s+=arr[i];
	    
	    for(int i=0;i<=n;i++){
	        dp.push_back(vector<int>(s+1,-1));
	    }
	    
	    int t=s/2;
	    int x=knp(arr,n,t);
	   
	    int y=s-x;
	    return (y-x);
	} 
