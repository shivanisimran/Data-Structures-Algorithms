/*
Complete the function minValue() which takes root as the argument and returns the minimum element of BST. 
If the tree is empty, there is no minimum elemnt, so retutn -1 in that case.

Solution:                                                                                                            */
int minValue(Node* root)
{
    // Code here
    if(root==NULL){
        return -1;
    }
    while(root->left){
        root=root->left;
    }
    return root->data;
}
