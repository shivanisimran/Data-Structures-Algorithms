/*
Given a Binary Tree, write a function to populate next pointer for all nodes. 
The next pointer for every node should be set to point to inorder successor.

Solution:                                                               */
    void inorder(Node*root, vector<Node*>& v){
        if(root==NULL)
             return;
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
    void populateNext(Node *root)
    {
        //code here
        vector<Node*> v;
        inorder(root,v);
        for(int i=0;i<v.size()-1;i++){
            v[i]->next=v[i+1];
        }
    }
