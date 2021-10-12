/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Solution:                                                                                                                                     */
    vector<vector<int>>ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> c;
        back(nums,c,0);
        return ans; 
    }
    void back(vector<int>&nums,vector<int>c,int x){
        int n=nums.size();       
        ans.push_back(c);
        for(int i=x;i<n;i++){
            c.push_back(nums[i]);
            back(nums,c,i+1);
            c.pop_back();
        }
    }
