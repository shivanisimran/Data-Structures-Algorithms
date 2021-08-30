/*
Complete the function insert() which takes the root of the BST and Key K as input parameters 
and returns the root of the modified BST after inserting K. 

Solution:                                                                                                                                */
Node* insert(Node* root, int Key)
{
    // Your code here
    if(root==NULL){
        return new Node(Key);
    }
    if(root->data < Key){
        root->right=insert(root->right,Key);
    }
    else if(root->data > Key){
        root->left=insert(root->left,Key);
    }
    else{
         return root;
    }
   
}
