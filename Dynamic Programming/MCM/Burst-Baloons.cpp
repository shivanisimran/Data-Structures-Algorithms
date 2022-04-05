/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, 
then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167


Solution:                                                                                                                                   */
    int dp[303][303];
    int mcm(vector<int>& arr,int i,int j){
        if(dp[i][j]!=-1)  return dp[i][j];
        if(i==j)    return dp[i][j]= 0;
        int m=INT_MIN;
        for(int k=i;k<j;k++){
            m=max(m, arr[i-1]*arr[k]*arr[j]
                     + mcm(arr,i,k)
                     + mcm(arr,k+1,j)
                 );
        }
        return dp[i][j]= m;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(1);
        for(int i: nums)  arr.push_back(i);
        arr.push_back(1);
        int n=arr.size();
        
        memset(dp,-1,sizeof dp);
        return mcm(arr,1,n-1);
    }
