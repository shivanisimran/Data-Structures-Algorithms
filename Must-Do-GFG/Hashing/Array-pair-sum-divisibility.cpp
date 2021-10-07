/*
Given an array of integers and a number k, write a function that returns true 
if given array can be divided into pairs such that sum of every pair is divisible by k.

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

Solution:                                                                                                      */
     bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        if(n&1) return false;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i] % k]++;
        }
        int c=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i] % k;
            if(x==0)    c++;
            if(x!=0 && mp[k-x]<mp[x])    return false;
           
        }
        if(c&1) return false;
        return true;
    }
