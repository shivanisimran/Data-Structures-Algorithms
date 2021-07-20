/* Your task is to complete the function height() which takes root node of the tree as input parameter 
   and returns an integer denoting the height of the tree. 
   If the tree is empty, return 0. 
   
Solution: Solved using Base,Hypothesis,Induction method. */
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node==NULL)
            return 0;
        return (1+max(height(node->left),height(node->right)))  ; 
    }
};
