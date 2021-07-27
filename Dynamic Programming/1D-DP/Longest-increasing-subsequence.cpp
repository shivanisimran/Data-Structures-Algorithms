/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Solution:
1. Initialize an array dp with length nums.length and all elements equal to 1. 
   dp[i] represents the length of the longest increasing subsequence that ends with the element at index i.

2. Iterate from i = 1 to i = nums.length - 1. At each iteration, use a second for loop to iterate from j = 0 to j = i - 1 (all the elements before i). 
   For each element before i, check if that element is smaller than nums[i]. If so, set dp[i] = max(dp[i], dp[j] + 1).

3. Return the max value from dp.  */

   int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        }
          return *max_element(dp.begin(),dp.end());
    }
