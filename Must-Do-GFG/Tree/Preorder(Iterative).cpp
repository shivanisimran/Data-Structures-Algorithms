/*
Given a binary tree. Find the preorder traversal of the tree without using recursion.

Solution:                                                                                                                                           */
   vector<int> preOrder(Node* root)
    {
        //code here
        vector<int> v;
        Node* curr=root;
        stack<Node* >st;
     
        while(!st.empty() || curr){
           
           while(curr){
               v.push_back(curr->data);
               st.push(curr);
               curr=curr->left;
            }
            curr = st.top();
            st.pop();
           
            curr=curr->right;
        }
       return v; 
    }
