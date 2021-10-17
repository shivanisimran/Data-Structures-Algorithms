/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Solution:                                                                                                                                */
    vector<vector<int>>ans;
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<int> v;
        back(root,v,t,0);
        return ans;
    }
    
    void back(TreeNode* root,vector<int> v,int t,int s){
        if(root==NULL)  return;
        v.push_back(root->val);
        s+=root->val;
        if(!root->left && !root->right){
           if(s==t)  ans.push_back(v);
            return;
        }
       
        back(root->left,v,t,s);
        back(root->right,v,t,s);
            
        
    }
    
