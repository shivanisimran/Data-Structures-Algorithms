/*
Given a binary tree. Find the inorder traversal of the tree without using recursion.
Expected time complexity: O(N)
Expected auxiliary space: O(N)

Solution:                                                                                                                                  */
  vector<int> inOrder(Node* root)
    {
        //code here
        vector<int> v;
        Node* curr=root;
        stack<Node* >st;
    
        while(!st.empty() || curr){
            while(curr){
               st.push(curr);
               curr=curr->left;
            }
            curr = st.top();
            st.pop();
            v.push_back(curr->data);
            curr=curr->right;
        }
       return v; 
    }
