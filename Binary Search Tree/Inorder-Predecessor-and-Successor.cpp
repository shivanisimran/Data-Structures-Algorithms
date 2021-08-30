/*
There is BST given with root node with key part as integer only. You need to find the inorder successor and predecessor of a given key. 
In case, if the either of predecessor or successor is not found print -1

Solution:                                                                                                                                  */
Node* succ(Node* root){
    Node* p=root->right;
    while(p->left){
        p=p->left;
    }
    return p;
}
Node* pree(Node* root){
    Node* p=root->left;
    while(p->right){
        p=p->right;
    }
    return p;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

// Your code goes here
   if(!root)return;
   if(root->key==key){
       if(root->right)
            suc=succ(root);
       if(root->left)
             pre=pree(root);
   }
   if(root->key > key){
       suc=root;
       findPreSuc(root->left,pre,suc,key);
   }
   if(root->key < key){
       pre=root;
       findPreSuc(root->right,pre,suc,key);
   }
}
