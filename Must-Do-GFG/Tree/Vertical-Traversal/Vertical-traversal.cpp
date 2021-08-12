/*
Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Solution:                                                 */
vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> v;
        if(root==NULL)
             return v;
        
        int hd=0;         
        map<Node*, int>mp;
        map<int, vector<int>>mp1;
        
        mp[root]=hd;
        
        queue<Node* >q;
        q.push(root);
        while(!q.empty()){
           Node* k= q.front();
           q.pop();
           hd=mp[k];
           mp1[hd].push_back(k->data);
           if(k->left){
               mp[k->left]=hd-1;
               q.push(k->left);
           }
           if(k->right){
               mp[k->right]=hd+1;
               q.push(k->right);
           }
        }
        for(auto i:mp1){
            for(int j=0;j<i.second.size();j++){ // Traverse through all distances, starting from leftmost to rightmost.
                v.push_back(i.second[j]); //prints all the nodes of a partcular distance.
            }
        }
        return v;
    }
