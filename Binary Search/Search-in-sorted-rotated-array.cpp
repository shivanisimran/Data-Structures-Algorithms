/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Solution:                                                                                                                             */
int search(vector<int>& nums, int t) {
        int l=0,h=nums.size()-1;
        while(l <= h){
            int m= l+(h-l)/2;
            if(nums[m]==t)  return m;
            
            else if(nums[l]<=nums[m]){ 
                if(nums[m]>t && nums[l]<=t)   h=m-1;
                else l=m+1;
            }
            
            else{
                if(nums[m]<t && nums[h]>=t)   l=m+1;
                else h=m-1;
            }
        }
        
        return -1;
    }
