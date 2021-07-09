/*
Given a binary tree. Check whether it is a BST or not.
Your task is to complete the function isBST() which takes the root of the tree as a parameter 
and returns true if the given binary tree is BST, else returns false. 

Solution:
I have used the fact that Inorder traversal of binary search tree gives array in increasing order.
So, I just found the Inorder traversal, and, checked whether it is in increasing order or not. */

void inorder(Node* root,vector<int>&v){
     
        if(root==NULL){
            return;
        }
       
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
        
       
    }
    bool isBST(Node* root) 
    {
        // Your code here
        vector<int> v;
        inorder(root,v);
         //cout<<v[2]<<" ";
        for(int i=1;i<v.size();i++){
           
            if(v[i]<=v[i-1])
                 return false;
        }
        return true;   
    }
