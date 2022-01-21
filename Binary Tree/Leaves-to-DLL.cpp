/*
Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List starting from the left most leaf. 
Modify the original tree to make the DLL thus removing the leaf nodes from the tree. 
Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.

Note:
The generated output will contain the inorder traversal of the modified tree, the DLL from left to right and the DLL from right to left.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(height of tree)

Input:
1
1 2 3 4 5 6 7

Output:
2 1 3 
4 5 6 7 
7 6 5 4 


Solution:                                                                                                                                           */
Node* first=new Node(-1);
Node* head=first;

void fn(Node *root){
    if(!root || (!root->left && !root->right))  return;
    if(root->left){
        if(!root->left->left && !root->left->right)  {
           head->right=(root->left);
           if(head->data==-1)  root->left->left=NULL;
           else root->left->left=head;
           head=head->right;
           root->left=NULL;
        }
    }
    fn(root->left);
    if(root->right){
        if(!root->right->left && !root->right->right)  {
           head->right=(root->right);
           if(head->data==-1)  root->right->left=NULL;
           else root->right->left=head;
           head=head->right;
           root->right=NULL;
        }
    }
   
    fn(root->right);
}
Node * convertToDLL(Node *root){
    // add code here.
    if(root==NULL)  return NULL;
    
    //global variables may have values of previous test cases. 
    //so, we need to re-define at each test case.
    first=new Node(-1);
    head=first;
    
    fn(root);
    
    return first->right;
}
