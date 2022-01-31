/*
Given a binary tree and a node, print all cousins of given node in order of their appearance. 
Note that siblings should not be printed.

If there is no cousin of the given node, return -1 as the first element of the list.

Solution:                                                                                                                                              */
    unordered_map<int,int>parent;
    void par(Node* root){
        if(!root || (!root->left && !root->right))  return;
        if(root->left) parent[root->left->data]=root->data;
        if(root->right) parent[root->right->data]=root->data;
        par(root->left);
        par(root->right);
    }

    vector<int> printCousins(Node* root, Node* t)
    {
        //code here
        par(root);
        queue<Node*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int n=q.size();
            int vis[100000]={0};
            vector<int> v;
            while(n--){
                Node* k=q.front();
                q.pop();
                v.push_back(k->data);
                vis[k->data]=1;
                if(k->left) q.push(k->left);
                if(k->right) q.push(k->right);
            }
            if(vis[t->data]){
                for(int i: v){
                    if(parent[i]!=parent[t->data]) ans.push_back(i);
                }
                if(ans.size()>0) return ans;
            }
        }
        return {-1};
        
    }
