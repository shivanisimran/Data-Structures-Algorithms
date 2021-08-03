/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. 
Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.    

Solution: 
We can do this with binary search.
First, we find middle element and, check weather this is single or not.If yes, then return it.
Otherwise, using the index of middle element, we see how many numbers are before and after mid. 
The part which has single element would have odd no. of elements excluding middle element and its pair.
         
CODE:                                                         */
int singleNonDuplicate(vector<int>& nums) {
      int l=0,r=nums.size()-1;
      while(l<=r){
        int m=l+(r-l)/2;
        if(m%2==0){
              if(m==0 || nums[m]!=nums[m-1] && nums[m]!=nums[m+1])
                return nums[m];
            else if(nums[m]==nums[m-1])
                r=m-1;
            else
                l=m+1;
        }
        else{
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1])
                return nums[m];
            else if(nums[m]==nums[m-1])
                l=m+1;
            else
                r=m-1;
        }
    }
        
        return -1;
    }

