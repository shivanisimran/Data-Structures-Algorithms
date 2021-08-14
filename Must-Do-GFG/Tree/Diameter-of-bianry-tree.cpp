/*
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree.

Solution: Length of path passing through any node would be height of its left subtree + height of right subtree + the node itself.
          So, we recursively check for each node and return the node which gives maximum diameter.
          
CODE:                                                                                                    */
int height(Node *root){
    if(root==NULL)
         return 0;
    return 1+max(height(root->left), height(root->right));
}
int d(Node* root){
    if(root==NULL)
         return 1;
    int l=height(root->left);
    int r=height(root->right);
    return l+r+1;
}

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        if(root==NULL)
         return 0;
        return max({d(root), diameter(root->left), diameter(root->right)});
    }
};
