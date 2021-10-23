/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

Input: nums = [2,2,2,0,1]
Output: 0

Solution:                                                                                                                                         */
     int l=0,r=nums.size()-1;
       while(l<r){ 
            int m=l+(r-l)/2;
            while(r>l && nums[m]==nums[l] && nums[m]==nums[r]){
                l++;r--;
            }
            
            if(nums[r]>nums[l]) {
                 return nums[l];
            } 
            if(nums[m]>=nums[l]) l=m+1;
            else    r=m;
        }

        return nums[l];
    }
