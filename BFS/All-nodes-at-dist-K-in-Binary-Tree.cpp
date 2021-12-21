/*
Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Solution:                                                                                                                                                              */

    //to find parent of current node
    unordered_map<TreeNode*,TreeNode*>par;
    void findpar(TreeNode* root){
        if(!root) return;
        if(root->left)  par[root->left]=root;
        if(root->right)  par[root->right]=root;
        
        findpar(root->left);
        findpar(root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*,int>vis;
        
        findpar(root);
        vector<int> ans;
        q.push(target);
        int c=0 ;
        
        //doing BFS
        while(!q.empty()){
            c++;
            int n=q.size();
            vector<int>v;
          
            while(n--){
                TreeNode* f=q.front();
                q.pop();
                vis[f]=1;
                v.push_back(f->val);
                if(f->left && !vis[f->left]) q.push(f->left);
                if(f->right && !vis[f->right]) q.push(f->right);
                if(f!=root && !vis[par[f]]) q.push(par[f]);
            }
           
            if(c==k+1) return v;  
        }
        
        return ans;
    }
