/*
Complete the function LCA() which takes the root Node of the BST and two integer values n1 and n2 as inputs 
and returns the Lowest Common Ancestor of the Nodes with values n1 and n2 in the given BST. 

Solution:   For Binary search tree, while traversing the tree from top to bottom the first node which lies in between the two numbers n1 and n2 is the LCA of the nodes, 
            i.e. the first node n with the lowest depth which lies in between n1 and n2 (n1 <= n <= n2) n1 < n2.

CODE:                                                                                                    */
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(n1>n2)
      swap(n1,n2);
   if(root==NULL)
       return NULL;
   if(root->data >= n1 && root->data <=n2) 
        return root;
   else if(root->data >= n2) {
       LCA(root->left,n1,n2);
   }   
   else if(root->data <= n1){
       LCA(root->right,n1,n2);
   }
}
