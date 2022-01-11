/*
You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.

Solution:                                                                                                                                                              */
    vector<string> v;
    int convert(string s){
        int c=0;
        for(int i=0;i<s.length();i++){
            c = c*2 + (s[i]-'0');
        }
        
        return c;
    }
    
    void dfs(TreeNode* root, string s){
        s+=to_string(root->val);
       
        if(root->left){
           // if(!vis[root->left]) 
            dfs(root->left,s);
        }
        if(root->right){
            //if(!vis[root->right])
            dfs(root->right,s);
        }
        
        if(!root->left && !root->right) v.push_back(s);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        dfs(root,"");
        int ans=0;
        for(string s: v) ans+=convert(s);
        return ans;
    }
