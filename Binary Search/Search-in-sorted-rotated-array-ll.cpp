/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Solution:                                                                                                                                      */
     bool search(vector<int>& nums, int t) {
       int l=0,h=nums.size()-1;
        while(l <= h){
            int m= l+(h-l)/2;
            if(nums[m]==t)  return 1;
            
            while(l<h && nums[m]==nums[l] && nums[m]==nums[h]){
                l++;h--;
            }
            if(nums[l]<=nums[m]){
                if(nums[m]>t && nums[l]<=t)   h=m-1;
                else l=m+1;
            }
            else{
                if(nums[m]<t && nums[h]>=t)   l=m+1;
                else h=m-1;
            }
        }
        
        return 0;
        
    }
