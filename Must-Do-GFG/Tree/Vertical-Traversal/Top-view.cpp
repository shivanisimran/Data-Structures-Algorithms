/*
Given below is a binary tree. The task is to print the top view of binary tree. 
Top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Solution: To find the top view, we do the similar thing we did in finding the bottom view.
          The only difference is that, in bottom view, we take the bottom-most of all nodes at each horizontal distance,
          but, for Top-view, we take the topmost node of all nodes present at each horizontal distance.
          
          
CODE:                                                                  */
vector<int> topView(Node *root)
    {
        //Your code here
    vector<int> v;
    if (root == NULL)
        return v;

   
    int hd = 0;
    map<int, vector<int>> m;
    map<Node* ,int> m1;

    queue<Node *> q;
    m1[root] = hd;
    q.push(root); 
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();  
        hd = m1[temp];
        m[hd].push_back(temp->data);
        if (temp->left != NULL)
        {
            m1[temp->left]= hd-1;
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            m1[temp->right] = hd+1;
            q.push(temp->right);
        }
    }

    for(auto i:m){
        //since,it is level-order traversal,the first node at each horizonal dist. will be the top-most node for this horizontal dist.
        v.push_back(i.second[0]); 
    }
    return v;
    
 }
