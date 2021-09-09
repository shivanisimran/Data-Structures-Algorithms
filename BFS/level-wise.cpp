/*
when we need data for each level separately in a binary tree we collect the data separately for each level using a queue, 
and traversing the queue for all elements in a particular level.
Then, similarly do for each level.                                               */

//Here are some questions which use similar concepts:

/*
1. Binary Tree Level Order Traversal
   Input: root = [3,9,20,null,null,15,7]
   Output: [[3],[9,20],[15,7]] */

  vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        vector<vector<int>> v1;
        if(root==NULL)
            return v1;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> v; //initializing an empty vector v at each level.
            for(int i=0;i<n;i++){
              TreeNode* k=q.front();
              q.pop();
              v.push_back(k->val);
              if(k->left)
                q.push(k->left);
              if(k->right)
                q.push(k->right);
           }
           //vector v contains all nodes of the respective level. so, pushing it to our output vector.
            v1.push_back(v);
        } 
        return v1;
      }

/*
2.  Maximum Level Sum of a Binary Tree
Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.*/

 int maxLevelSum(TreeNode* root) {
        queue<TreeNode* > q;
        int l=0,m=-100000,x=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int s=0;
            l++;
            for(int i=0;i<n;i++){
              TreeNode* k=q.front();
              q.pop();
              s+=k->val;
              if(k->left)
                q.push(k->left);
              if(k->right)
                q.push(k->right);
           }
           //calculating sum at each level and comparing with previous maximum value.
           if(m<s){ 
               m=s;
               x=l;
           }   
        }
        return x;
    }


/*
3. Find Largest Value in Each Tree Row.
   Input: root = [1,3,2,5,3,null,9]
   Output: [1,3,9] */

 vector<int> largestValues(TreeNode* root) {
        queue<TreeNode* > q;
        vector<int> v;
        if(root==NULL)
            return v;  
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            long long s=INT_MIN; // initializing the largest value before iterating each level
            for(int i=0;i<n;i++){
            TreeNode* k=q.front();
            q.pop();
            if(k->val>s) //updating the value if we encounter any value larger than our previous value.
                s=k->val;
            if(k->left)
                q.push(k->left);
            if(k->right)
                q.push(k->right);
            
           }
           v.push_back(s); // push the largest value of each level in a vector ,and return it.
        }    
        return v;
  
    }

/*
4. Given the root of a binary tree, return the leftmost value in the last row of the tree.
   Input: root = [1,2,3,4,null,5,6,null,null,7]
   Output: 7 */
int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        long long x;
        while(!q.empty()){
            vector<int> v; //creating a vector which will store all the node values of a particular level.
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* k=q.front();
                q.pop();
                v.push_back(k->val);
                if(k->left)
                    q.push(k->left);
                if(k->right)
                    q.push(k->right);
            }
            x=v[0]; // leftmost value will be contained in the 0'th index of vector. Since we have to get it for the last row, we update its value after eact row till the last row.
        }
        return x;
    }


/*
5.  Binary Tree Zigzag Level Order Traversal
    Return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between). */
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v1;
        int l=0;
        if(root==NULL)
            return v1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            l++; //taking a variable l and setting its value odd and even at alternate levels.
            vector<int> v;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* k=q.front();
                q.pop();
                v.push_back(k->val);
                if(k->left)
                    q.push(k->left);
                if(k->right)
                    q.push(k->right);
            }
            if(l%2==0) // reversing the vector at each even level, thus, we get the desired zig-zag traversal.
                reverse(v.begin(),v.end());
            v1.push_back(v);
        }
        return v1;
    }

 
