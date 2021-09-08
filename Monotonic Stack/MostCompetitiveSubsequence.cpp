/*
Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, 
subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because 
the first position they differ is at the final number, and 4 is less than 5.

Example :

Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.

Solution:                                                                                                                             */
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> st;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && st.top()>nums[i] && st.size()+n-i>k)
                st.pop();
            st.push(nums[i]);
        }
        vector<int> v;
        vector<int>ans(k);
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<k;i++){
            ans[i]=v[i];
        }
        return ans;    
    }
