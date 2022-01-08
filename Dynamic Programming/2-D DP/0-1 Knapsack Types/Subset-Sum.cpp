/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 
Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

Solution:                                                                                                                              */
    int dp[1001][1001];
    bool func(int n,int arr[],int sum){
        // if(sum==0) return true;
        // if(n==0 && sum!=0) return false;
        // return func(n-1,arr,sum-arr[n-1])||func(n-1,arr,sum);
       
        if(sum==0) return 1;
        if(n==0) return 0;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        if(arr[n-1]<=sum)  
            return dp[n][sum] = func(n-1,arr,sum-arr[n-1])||func(n-1,arr,sum);
        else return dp[n][sum] = func(n-1,arr,sum);
    }
    bool isSubsetSum(int n, int arr[], int sum){
        // code here 
        memset(dp,-1,sizeof(dp));
        return func(n,arr,sum);
    }
