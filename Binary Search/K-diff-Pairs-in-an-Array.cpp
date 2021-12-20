/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.

Solution:                                                                                                                                            */
  int findPairs(vector<int>& nums, int k) {
        set< pair<int,int>>st; 
        int c=0;
        sort(nums.begin(),nums.end());
        
        for(int i=nums.size()-1; i>0 ; i--){
            int l=0,r=i-1;
            
            while(l<=r){
                int m=l+(r-l)/2;
                if(nums[i]-nums[m] > k)  l=m+1;
                else if(nums[i]-nums[m] < k)  r=m-1;
                else {
                    st.insert({nums[m],nums[i]});
                    break;
                }
            }
        }
        
        return st.size();
    }
