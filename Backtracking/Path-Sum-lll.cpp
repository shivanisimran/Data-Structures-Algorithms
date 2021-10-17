/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.

Solution:                                                                                                                              */
    int c=0;
    int pathSum(TreeNode* root, int t) {
        if(root==NULL) return c;
        back(root,t,0);
        pathSum(root->left,t);
        pathSum(root->right,t);
        return c;
    }
    void back(TreeNode* root,int t,int s){
        if(root==NULL)  return;
       
        s+=root->val;
        if(s==t)  c++;
        if(!root->left && !root->right){
            return;
        }
       
        
        back(root->left,t,s);
        back(root->right,t,s);
            
        
    }

 
