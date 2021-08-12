/*
Complete the function verticalSum() that takes root node of the tree as parameter and 
returns an array containing the vertical sum of tree from left to right.

Solution: For getting the vertical sum, we need to traverse the tree vertically for each horizontal distance. 
          Nodes having same horizontal distace would be kept in same group. Then, we have to find sum of all the nodes in each group.
          We will find horizonal distance of each node from root, represent it as 'hd' and, store in map where key is the node and, its value would be it's 
          horizontal distance from root, i.e, its hd.

CODE:                                     */
vector <int> verticalSum(Node *root) {
    // add code here.
    vector<int> v;
    if (root == NULL)
        return v;

   
    int hd = 0; // hd will store the horizontal distance of respective nodes.
  
    map<Node* ,int> m1; //for storing hd of each node.
    map<int, vector<int>> m;  //this map stores the values of all nodes for a given 'hd', i.e, values of all nodes at a particular horizontal dist. from root. 
                              //Those values are stored in a vector.
  
    queue<Node *> q;
    m1[root] = hd; //for root, we take hd as 0.
    q.push(root); 
    while (!q.empty()) //doing bfs traversal
    {
        Node *temp = q.front();
        q.pop();  
        hd = m1[temp];
        m[hd].push_back(temp->data);
        if (temp->left != NULL)
        {
            m1[temp->left]= hd-1; //reducing hd, as we go left.
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            m1[temp->right] = hd+1;  //incrementing hd ,as going right.
            q.push(temp->right);
        }
    }

    for (auto i : m){
        int s=0;
        for(int j=0;j<i.second.size();j++) //i.second is a vector which contains all nodes at hd=i.
              s+=i.second[j]; // finding sum of all nodes at hd=i.
        v.push_back(s);          
    }
      return v;  
    }
