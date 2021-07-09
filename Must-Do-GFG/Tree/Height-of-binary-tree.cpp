/*
Given a binary tree, find its height.
Complete the function height() which takes root node of the tree as input parameter
and returns an integer denoting the height of the tree. If the tree is empty, return 0. 

Solution: We have to just count the number of levels in the tree. For that, we use level-order traversal. */

int height(struct Node* node){
        // code here 
        queue<Node* >q;
        int h=0;
        if(node==NULL)
           return 0;
        q.push(node);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node *k = q.front();
                q.pop();
                if(k->left)
                    q.push(k->left);
                if(k->right)
                    q.push(k->right);
            }
            h++;
        }
        return h;
    }
