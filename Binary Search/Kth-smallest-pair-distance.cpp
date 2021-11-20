/*
The distance of a pair of integers a and b is defined as the absolute difference between a and b.
Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Solution:                                                                                                                             */
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=1000000,ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(countless(mid,nums)>=k){
                ans=mid;
                r=mid-1;
            }
            else    l=mid+1;     
        }
        return ans;
    }
    int countless(int x,vector<int>&nums){
         int n=nums.size(),c=0;
         int j=0;
         for(int i=0;i<n;i++){
             while(j<n && nums[j]-nums[i]<=x) j++;
             c += j-i-1;
         }
        return c;
    }
