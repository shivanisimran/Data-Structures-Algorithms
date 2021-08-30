/*
Complete the function inOrderSuccessor(). This function takes the root node and the reference node as argument and returns the node 
that is inOrder successor of the reference node. 
If there is no successor, return null value.

Solution:                                                                                    */

    Node* succ(Node* root){
       Node* p=root->right;
       while(p->left)
            p=p->left;
       return p;
    }

    Node* suc=NULL;
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        if(root->data == x->data){
            if(root->right)
                 suc = succ(root);
        }
        if(root->data > x->data){
            suc=root;
            inOrderSuccessor(root->left,x);
        }
         if(root->data < x->data){
            inOrderSuccessor(root->right,x);
        }
        return suc;
    }
