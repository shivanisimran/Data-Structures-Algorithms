/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses. 

Solution:
Since House[1] and House[n] are adjacent, they cannot be robbed together. 
Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. 
Now the problem has degenerated to the House Robber, which is already been solved.
*/
int rob(vector<int>& nums) {
        int n=nums.size();
         if(n==1)
            return nums[0];
         if(n==2)
             return max(nums[0],nums[1]);
         if(n==3){
            sort(nums.begin(),nums.end());
             return nums[n-1];
         }
             
        int dp[n];
        dp[0]=0;
        dp[1]=nums[0];
        dp[2]=max(nums[0],nums[1]);
        for(int i=3;i<n;i++){
            dp[i]=max(nums[i-1]+dp[i-2], dp[i-1]);
        }
        int x=dp[n-1];
        
        int dp1[n+1];
        
        dp1[0]=0;
        dp1[1]=0;
        dp1[2]=nums[1];
        dp1[3]=max(nums[1],nums[2]);
        for(int i=4;i<=n;i++){
            dp1[i]=max(nums[i-1]+dp1[i-2], dp1[i-1]);
        }
        int y=dp1[n];
        
        return max(x,y);
    }

 
