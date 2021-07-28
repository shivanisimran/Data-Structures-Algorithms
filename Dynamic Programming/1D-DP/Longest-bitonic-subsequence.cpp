/*
Your task is to complete the function LongestBitonicSequence() 
which takes the array nums[] as input parameter and returns the maximum length of bitonic subsequence.
A subsequence of array is called Bitonic if it is first increasing, then decreasing.

Example:
Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence 
{1, 2, 10, 4, 2, 1} has length 6.

Solution:
This problem is a variation of standard Longest Increasing Subsequence (LIS) problem.
Let the input array be nums[] of length n. 
We need to construct two arrays dp[] and dp1[]
dp[i] stores the length of the Longest Increasing subsequence ending with nums[i]
dp1[i] stores the length of the longest Decreasing subsequence starting from nums[i]
Finally, we need to return the max value of dp[i] + dp1[i] – 1 where i is from 0 to n-1.

CODE:      */
int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n=nums.size();
	    vector<int> dp(n,1);
	    vector<int> dp1(n,1);
	    vector<int> dp2(n,1);
      
      //finding the length of the Longest Increasing subsequence ending with nums[i]
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[j]<nums[i])
	                 dp[i]=max(dp[i],dp[j]+1);
	        }
	    }
  
      //finding the length of the longest Decreasing subsequence starting from nums[i]
	    for(int i=n-2;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(nums[j]<nums[i])
	                dp1[i]=max(dp1[i],dp1[j]+1) ;
	        }
	    }
     
     //for getting max value of dp[i] + dp1[i] – 1
	   for(int i=0;i<n;i++){
	       dp2[i]=dp[i]+dp1[i]-1;
	   }
	    return *max_element(dp2.begin(),dp2.end());
	}
