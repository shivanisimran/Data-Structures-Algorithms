/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

Solution:  To check if a tree is height-balanced, get the height of left and right subtrees. 
           Return true if difference between heights is not more than 1 and left and right subtrees are balanced, otherwise return false. 
           
CODE:                                                                        */
int height(Node *root){
    if(root==NULL)
         return 0;
    return 1+max(height(root->left), height(root->right));
}
bool isBalanced(Node *root)
{
    //  Your Code here
    if(root==NULL)
         return true;
    int l=height(root->left);
    int r=height(root->right);
    
    return(abs(l-r)<=1 && isBalanced(root->left) && isBalanced(root->right));
}
