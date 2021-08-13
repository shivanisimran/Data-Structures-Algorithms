/*
Given a binary tree, connect the nodes that are at same level. 
You'll be given an addition nextRight pointer for the same.
Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.

Complete the function connect() that takes root as parameter and connects the nodes at same level. 

Solution: We perform level order traversal and, connect adjacent nodes at each level using the nextRight pointer.

CODE:                                                                                        */
void connect(Node *root)
    {
       // Your Code Here
       queue<Node* > q;
        if(root==NULL)
            return ;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<Node* > v;
            for(int i=0;i<n;i++){
              Node* k=q.front();
              q.pop();
              v.push_back(k);
              if(k->left)
                q.push(k->left);
              if(k->right)
                q.push(k->right);
           }
            for(int i=0;i<v.size()-1;i++){
                v[i]->nextRight=v[i+1]; //connecting all adjacent nodes of a particular level.
            }
            v[v.size()-1]->nextRight=NULL;
        } 
      
    }    
      
