/*
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.

Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph 
starting from the 0th vertex, from left to right according to the graph. 
Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

Solution:                                                                                                                */
 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> v;
        vector<bool>vis(V,false);
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int k=q.front();
            v.push_back(k);
            q.pop();
            for(int i=0;i<adj[k].size();i++){
                if(!vis[adj[k][i]]){
                      vis[adj[k][i]]=true;
                      q.push(adj[k][i]);
                }
            }
        }
        return v;
    }
