//Given a binary tree, find its level order traversal.
// Complete the function levelOrder() that takes the root node as input parameter and returns a list of integers containing the level order traversal of the given Binary Tree.


class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> v;
      queue<Node *> q;
      if(node==NULL)
          return v;
      q.push(node);
      
      while(!q.empty()){
          Node *l=q.front();
          v.push_back(l->data);
          q.pop();
          if(l->left!=NULL)
              q.push(l->left);
          if(l->right!=NULL)       
              q.push(l->right);
      }
      
      return v;
    }
};
