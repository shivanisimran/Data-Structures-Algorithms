/*
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

Input: nums = [1,2,3,4]
Output: 3
Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself. */

int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int>dp(n,0);
        if(n<3)
            return 0;
        for(int i=2;i<n;i++) {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                dp[i]=dp[i-1]+1; // finding no. of subarray ending at index 'i' which is one more than prev. index
                ans+=dp[i]; // adding subarrays count  of all index from 2 to n-1.
            }
            else
                dp[i]=0;
                 
        } 
        return ans;
    }
