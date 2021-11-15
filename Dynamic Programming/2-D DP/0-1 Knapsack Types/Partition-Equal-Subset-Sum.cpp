/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets 
such that the sum of elements in both subsets is equal.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Solution:                                                                                                                             */
    dp[201][20001];
    int knp(int s,vector<int>& st,int n){
        if(n==0 || s==0)    return 0;
        
        if(dp[n][s] != -1)  return dp[n][s];
        if(st[n-1]<=s) return dp[n][s] = max(st[n-1]+knp(s-st[n-1],st,n-1), knp(s,st,n-1));
        else return dp[n][s] = knp(s,st,n-1);
    }
    
    bool canPartition(vector<int>& nums) {
        int s=0,t;
        int n=nums.size();
        for(int i=0;i<n;i++)    s+=nums[i];
        t=s;
        s/=2;
        memset(dp,-1,sizeof(dp));
        return t-2*knp(s,nums,n)==0;
    }
