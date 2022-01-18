/*
Given a binary tree with a value associated with each node, we need to choose a subset of these nodes such that sum of chosen nodes is maximum 
under a constraint that no two chosen node in subset should be directly connected that is, 
if we have taken a node in our sum then we can’t take its any children or parents in consideration and vice versa.

Solution: We can either pick a node or leave a node, then check when we are getting maxm output.                                                                     */

    unordered_map<Node*,int> dp;
    int knp(Node *root){
        if(dp[root]) return dp[root];
        if(root==NULL)  return 0;
        if(!root->left && !root->right)  return root->data;
        if(root->left && root->right) {
             return dp[root]= max(root->data+knp(root->left->left)+knp(root->left->right)+knp(root->right->left)+knp(root->right->right), knp(root->left)+knp(root->right));
        }
        if(root->left)  return dp[root]= max(root->data+knp(root->left->left)+knp(root->left->right), knp(root->left)+knp(root->right));
        if(root->right) return dp[root]=max(root->data+knp(root->right->left)+knp(root->right->right), knp(root->left)+knp(root->right));
       
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        return knp(root);
    }
