/*
Given a Binary Tree of size N , You have to count leaves in it.

Solution: Check the root is leave or not, If yes then total number of leaves will be 1 
          otherwise, calculate the answer recursively with the help of children. */


int countLeaves(Node* root)
{
  // Your code here
   
   if(root==NULL)
      return 0;
   if(root->left==NULL && root->right==NULL)
        return 1; 
    return  countLeaves(root->left)+countLeaves(root->right);
     
         
    
}
