/*
Given a binary tree. Find the postorder traversal of the tree without using recursion.

Solution: Postorder = left->right->root.
          So, we can find (root->right->left) and reverse it.
     
*/
  vector<int> postOrder(Node* root) {
        // code here
        vector<int> v;
        Node* curr=root;
        stack<Node* >st;
        while(!st.empty() || curr){
           while(curr){
               v.push_back(curr->data);
               st.push(curr);
               curr=curr->right;
            }
            curr=st.top();
            st.pop();
            curr=curr->left;
        }
       reverse(v.begin(),v.end());
       return v;
    }
