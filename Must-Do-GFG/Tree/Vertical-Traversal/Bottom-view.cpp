/*
Complete the function bottomView() which takes the root node of the tree as input and 
returns an array containing the bottom view of the given tree.

Sloution: We have to vertically traverse for each horizontal distance.
          A node x is there in output if x is the bottommost node at its horizontal distance. 
          
CODE:                                                              */
vector <int> bottomView(Node *root) {
    // Your Code Here
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
        //since,it is level-order traversal,the last node at each horizonal dist. will be the bottom-most node for this horizontal dist.
        v.push_back(i.second[i.second.size()-1]); 
    }
    return v;
    
    }
