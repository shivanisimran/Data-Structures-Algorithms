/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

1)Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could 
  reach when you always travel preferring the left subtree over the right subtree. 
2)Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
3)Reverse right boundary nodes: defined as the path from the right-most node to the root.
  The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree.
  Exclude the root from this as it was already included in the traversal of left boundary nodes. 
  
Solution:                                                                                                              */
void leaf(Node* root, vector<int>& ans){
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    } 
    leaf(root->left,ans);
    leaf(root->right,ans);
}

void Left(Node* root, vector<int>& ans){
    if(root==NULL)
         return;
    if(root->left){
        ans.push_back(root->data);
        Left(root->left,ans);
    }
    else if(root->right){
        ans.push_back(root->data);
        Left(root->right,ans);
    }
}

void Right(Node* root, vector<int>& ans , vector<int>& v){
    if(root==NULL)
         return;
    if(root->right){
        v.push_back(root->data);
        Right(root->right,ans,v);
    }
    else if(root->left){
        v.push_back(root->data);
        Right(root->left,ans,v);
    }
    
    
}

    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        vector<int> v;
        if(root==NULL)
             return ans;
        ans.push_back(root->data);
        Left(root->left, ans);
        leaf(root, ans);
        Right(root->right,ans,v);
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i]);
        }
        return ans;
    }
