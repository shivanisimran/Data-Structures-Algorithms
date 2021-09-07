/*
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]

Solution:                                                                                                                     */
 vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v(nums2.size(),-1);
        stack<int> st;
        map<int,int>mp;
        for(int i=0;i<nums2.size();i++)
            mp[nums2[i]]=i;
         for(int i=0;i<nums2.size();i++){
             while(!st.empty() && st.top()<nums2[i]){
                 v[mp[st.top()]]=nums2[i];
                 st.pop();
             }
             st.push(nums2[i]);
         }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(v[mp[nums1[i]]]);
        }
        return ans;
    }
