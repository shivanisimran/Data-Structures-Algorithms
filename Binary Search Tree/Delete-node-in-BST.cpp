/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

Solution:                                                                                                                        */
TreeNode* Max(TreeNode* t){
        if(!t)
            return NULL;
        while(t->right)
            t=t->right;
        return t;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp;
       // TreeNode* x=root;
        if(root==NULL)
             return NULL;
        if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else if(root->val < key)
            root->right = deleteNode(root->right,key);
        
        else{
            if(root->left && root->right){
               temp=Max(root->left);
                root->val=temp->val;
                root->left=deleteNode(root->left,temp->val);
                return root;
            }
            else if(root->left!=NULL){
                root= root->left;
            }
            else if(root->right!=NULL){
                root= root->right;
            }
            else{
                return NULL;
            }
        }
        
        return root;
    }
