/*
Given a Binary Tree, print Left view of it. 
Left view of a Binary Tree is set of nodes visible when tree is visited from Left side.
complete the function leftView() that prints the left view. */

vector<int> leftView(Node *root)
{
   // Your code here
   queue<Node* >q;
   vector<int> v;
   if(root==NULL)
       return v;
   q.push(root);
   while(!q.empty()){
      int n=q.size();
      vector<int> v1;
      for(int i=0;i<n;i++){
       
       Node* k=q.front();
       v1.push_back(k->data);
       q.pop();
       if(k->left)
          q.push(k->left);
       if(k->right)
           q.push(k->right);
      } 
      v.push_back(v1[0]);
   }
   return v;
}
