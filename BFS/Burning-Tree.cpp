/*
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. 
It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.

Solution:                                                                                                                                    */
    //to find parent of current node
    unordered_map<Node*,Node*>par;
    void findpar(Node* root){
        if(!root) return;
        if(root->left)  par[root->left]=root;
        if(root->right)  par[root->right]=root;
        
        findpar(root->left);
        findpar(root->right);
    }
    
    //to find pointer to the node with given value
    Node* find(Node* root, int t){
        //cout<<root->data<<" "<<t<<endl;
        Node* result = NULL;
        if(root->data == t) return root;
        
        if(root->left)  result=find(root->left,t);
        if(result==NULL && root->right)  result=find(root->right,t);
        
        return result;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node* t = find(root,target);
        findpar(root);
        //cout<<t->data<<" ";
        queue<Node*> q;
        
        unordered_map<Node*,int>vis;
      
      
        q.push(t);
        int c=0 ;
      
        //doing BFS
        while(!q.empty()){
            c++;
            int n=q.size();
            
            while(n--){
                Node* f=q.front();
                q.pop();
                vis[f]=1;
               
                if(f->left && !vis[f->left]) q.push(f->left);
                if(f->right && !vis[f->right]) q.push(f->right);
                if(f!=root && !vis[par[f]]) q.push(par[f]);
            }
        
        }
        
        return c-1;
    }
