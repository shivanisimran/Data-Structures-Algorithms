/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that 
adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4. */

int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        if(n==1)
            return nums[0];
        dp[0]=0;
        dp[1]=nums[0];  // for one house
        dp[2]=max(nums[0],nums[1]); // For 2 houses
        
        // we will create dp array for each n
        for(int i=3;i<=n;i++){ 
            dp[i]=max(nums[i-1]+dp[i-2], dp[i-1]); 
        }
        return dp[n];
    }

 
