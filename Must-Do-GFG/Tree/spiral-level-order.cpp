vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> v;
    int l=0;
    if(root==NULL)
       return v;
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        l++;
        vector<int> v1;
        int n=q.size();
        for(int i=0;i<n;i++){
            Node * k=q.front();
            q.pop();
            v1.push_back(k->data);
            if(k->left)
                q.push(k->left);
            if(k->right)
                 q.push(k->right);
        }
        if(l%2 != 0){
            reverse(v1.begin(),v1.end());
        }
        for(int i=0;i<v1.size();i++)
             v.push_back(v1[i]);
    }
    return v;
}
