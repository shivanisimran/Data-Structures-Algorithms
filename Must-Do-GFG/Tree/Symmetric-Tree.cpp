/*
Complete the function isMirror() which takes the root of the Binary Tree as its input and 
returns True if the given Binary Tree is Symmetric, i.e. a same as the Mirror image of itself. Else, it returns False.

Solution: We split the tree into two parts from the root, and check if both parts are mirror image of each other or not.
CODE:                                                                                           */
bool f(struct Node* a,struct Node* b){
    if(a==NULL && b==NULL)
        return true;
    if(a==NULL || b==NULL)   
         return false;
    if(a->data != b->data)   
         return false;
    return f(a->left,b->right) && f(a->right,b->left) ;    
}

bool isSymmetric(struct Node* root)
{
	// Code here
	if(root==NULL)
	   return true;
	return f(root->left,root->right);
}
