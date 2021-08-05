/*
You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.

Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.

Input: nums = [9], maxOperations = 2
Output: 3
Explanation: 
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.

Solution:  
All size i=of bag possible lies between 1 and maximum element of nums. So, we perform bianry search from 1 to max element of nums ,and check 
weather the number can be minimum possible size, which is possible if by taking that size, number of bags required <= (intial size of nums + m) ,because after m
moves, size will be increased by m from the initial size.                                               

CODE:                                                                                         */
int minimumSize(vector<int>& nums, int m) {
        long long l=1,r=*max_element(nums.begin(),nums.end());
        long long n=nums.size(),s=0,ans=0;
      
        
        n+=m; // maxm no. of bags possible after 'm' moves.
        while(l<=r){
            int s=0;
            int mid=l+(r-l)/2;
            for(int i=0;i<nums.size();i++){
                s+=(nums[i]+mid-1)/mid;  //'s' is the no. of bags required for this size.
            }
            if(s<=n){ // if 's' is less or equal to maxm no, we store the ans and, check for even smaller size.
                 ans= mid;
                  r=mid-1;
            }
               
            else if(s>n) // else, we check for larger size of bag.
                l=mid+1;
          
        }
        
        return ans;
    }
