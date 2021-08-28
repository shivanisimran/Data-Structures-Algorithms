/*
Complete the function minDepth() which takes the root node as an input parameter and returns the minimum depth.
Minimum depth is defined as  the number of nodes along the shortest path from the root node down to the nearest leaf node.

Solution:                                                                                                            */
int minDepth(Node *root) {
        // Your code here
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        if(l==0 || r==0){
            return (1+l+r);
        }
        return (1+min(l,r));
    }
