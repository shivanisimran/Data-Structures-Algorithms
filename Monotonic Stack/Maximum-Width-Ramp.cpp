/*
A ramp in an integer array nums is a pair (i, j) for which i < j and nums[i] <= nums[j]. The width of such a ramp is j - i.
Given an integer array nums, return the maximum width of a ramp in nums. If there is no ramp in nums, return 0.

Example :
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

Solution:                                                                                                   */
int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(st.empty()|| nums[st.top()]>nums[i])
                st.push(i);
        }
        for(int i=nums.size()-1;i>=0;i--){
           while(!st.empty() && nums[st.top()]<=nums[i]){
               res=max(res,i-st.top());
               st.pop();
           }  
        }
        
        return res;
    }
