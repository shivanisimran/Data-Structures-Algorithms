/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Solution:                                                                                                                   */
    set<vector<int>>st;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> c;
        vector<vector<int>>ans;
        back(nums,c,0);
        
        for(auto i: st) ans.push_back(i);
        return ans;  
    }
    
    void back(vector<int>&nums,vector<int>c,int x){
        int n=nums.size(); 
        if(!c.empty())  sort(c.begin(),c.end());
        st.insert(c);
        
        for(int i=x;i<n;i++){
            c.push_back(nums[i]);
            
            back(nums,c,i+1);
            c.pop_back();
        }
    }
