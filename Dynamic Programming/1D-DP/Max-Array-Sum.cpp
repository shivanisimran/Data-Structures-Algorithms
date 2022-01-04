/*
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. 
Calculate the sum of that subset. It is possible that the maximum sum is , the case when all elements are negative.

Example:
arr=[-2,1,3,-4,5]

The maximum subset sum is 8. Note that any individual element is a subset as well.

Solution:                                                                                                                                            */
int maxSubsetSum(vector<int> arr) {
      int n=arr.size();
      
      int dp[n];
      if(n==1) return max(0,arr[0]);
      
      dp[0]=max(0,arr[0]);
      dp[1]=max(dp[0],arr[1]);
      
      for(int i=2;i<n;i++) {
         
          dp[i]=max({dp[i-1],dp[i-2]+arr[i],dp[i-2]});
         
       }
      
      return dp[n-1];
}


