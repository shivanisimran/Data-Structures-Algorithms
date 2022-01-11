/*
You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.
Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.
As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

Input: root = [0,1,2,3,4,3,4]
Output: "dba"

Solution:                                                                                                                                                 */
 vector<string>v;
    void dfs(TreeNode* root, string s){
        s+=(root->val + 'a');
       
        if(root->left)  dfs(root->left,s);
        if(root->right) dfs(root->right,s);
        
        if(!root->left && !root->right){
            reverse(s.begin(),s.end());
            v.push_back(s);
        } 
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        sort(v.begin(),v.end());
        return v[0];
    }
