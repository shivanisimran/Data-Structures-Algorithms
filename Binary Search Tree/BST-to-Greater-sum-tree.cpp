/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is 
changed to the original key plus sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Solution: We find reverse Inorder traversal, which gives values in decreasing order, then, keep adding next values to previous calculated sum.   */
int sum=0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return root;
        bstToGst(root->right);
        int temp=root->val;
        sum+=temp;
        root->val=sum;
        bstToGst(root->left);
        
        return root;
    }
