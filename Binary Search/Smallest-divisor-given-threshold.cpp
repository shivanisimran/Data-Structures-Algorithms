/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. 
Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

It is guaranteed that there will be an answer.

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

Solution:
The divisor will be in the range 1(when threshold is maxm possible) to (maxm number+1)(when threshold is min).
So, we perform binary search from 1 to (maxm element+1) and find .

CODE:                                                                              */
int smallestDivisor(vector<int>& nums, int t) {
        int l=1,r=*max_element(nums.begin(),nums.end())+1,ans;
        while(l<=r){
            int m=l+(r-l)/2,s=0;
            for(int i=0;i<nums.size();i++){
                s+=(nums[i]+m-1)/m;
            }
           
            if(s<=t){ //if sum is less or equal 't' , we store this 'm' and check if there is even smaller 'm' exists for which sum <= t.
                ans=m;
                r=m-1;
            }
              
            else
                l=m+1; //else, we would check with bigger value of m.
        }
        return ans;
    }
