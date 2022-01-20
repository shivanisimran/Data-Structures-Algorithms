/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Solution: Let the sum of all elements of nums be sum. We can divide nums in two groups 'x' and 'y' one having '+' sign and other with '-' sign.
          So, x-y = target;
          So, the problem breaks down to finding number of subsets with the given difference.
          
CODE:                                                                                                                                                                */
    int dp[21][2000];
    int knp(vector<int>& nums, int t,int n){
        if(dp[n][t]!=-1)  return dp[n][t];
        if(t==0)  return 1;
        if(n==0)  return 0;
        
        if(nums[n-1]<=t) return dp[n][t] = knp(nums,t-nums[n-1],n-1) + knp(nums,t,n-1) ;
        return knp(nums,t,n-1);
    }
    
    int findTargetSumWays(vector<int>& nums, int t) {
        int n=nums.size();
        vector<int>v;
        memset(dp,-1,sizeof(dp));
        int sum=0,z=0;
        for(int i:nums)  {
            sum+=i;
            if(i==0) z++;
            else v.push_back(i);
        }
        if((sum+t)&1 || (sum+t)<0) return 0;
        return knp(v,(sum+t)/2,v.size()) *  (1 << z) ;
    }
