//when we need data for each level separately in a binary tree we collect the data separately for each level using a queue, and traversing the queue for all elements in a particular level.Then, similarly do for each level.

//Questions:

//1. Binary Tree Level Order Traversal
   //Input: root = [3,9,20,null,null,15,7]
   //Output: [[3],[9,20],[15,7]]

     vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        vector<vector<int>> v1;
        if(root==NULL)
            return v1;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
              TreeNode* k=q.front();
              q.pop();
              v.push_back(k->val);
              if(k->left)
                q.push(k->left);
              if(k->right)
                q.push(k->right);
           }
            v1.push_back(v);
        } 
        return v1;
      }
