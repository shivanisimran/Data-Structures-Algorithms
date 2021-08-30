/*
Complete the function sortedArrayToBST() which takes the sorted array nums as input paramater and returns the preorder traversal of height balanced BST. 
If there exist many such balanced BST consider the tree whose preorder is lexicographically smallest.

Solution:                                                                               */
void f(vector<int>& nums, int l, int r,vector<int>& ans){
        if(l>r)
             return;
             
        int mid=l+(r-l)/2;
        int t=nums[mid];
        ans.push_back(t);
        
        f(nums,l,mid-1,ans);
        f(nums,mid+1,r,ans);
        
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int> ans;
        f(nums,0,nums.size()-1,ans);
        
        return ans;
    }
