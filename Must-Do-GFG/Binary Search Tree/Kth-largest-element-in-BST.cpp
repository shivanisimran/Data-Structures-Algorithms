/*
Complete the function kthLargest() which takes the root of the BST and an integer K as inputs and returns the Kth largest element in the given BST.

Solution:                                                                                        */
void inorder(Node* root,vector<int>& v){
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        vector<int> v;
        inorder(root,v);
        
        return v[v.size()-K];
    }
