/*
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

Solution:                                                                                                                                                */

    //returns the size of array needed if subarray sum is 'm'
    int maxsize(vector<int>& nums, int m){
        int c=1,s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
            if(s>m){
                c++;
                s=nums[i];
            }
        }
      //  cout<<m<<" "<<c<<endl;
        return c;
    }
    
    int splitArray(vector<int>& nums, int t) {
        int n=nums.size(),max=0,ans;
        long long s=0;
        for(int i:nums){
            if(i>max)  max=i;
            s+=i;
        }
        long long l=max,r=s;
        while(l<=r){
            int m=l+(r-l)/2;
            if (maxsize(nums,m)<=t){
                ans=m;  
                r=m-1;  //if size is less, then we can afford to decrease the sum.
            }
            else l=m+1;
        }
        
        return ans;
    }
