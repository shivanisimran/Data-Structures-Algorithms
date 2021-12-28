/*
Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.

Solution:                                                                                                                                     */
    void dfs(int x,vector<int>&vis,vector<int> adj[]){
        vis[x]=1;
        for(auto k:adj[x]) {
           if(!vis[k]) dfs(k,vis,adj);
            
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        int i1,i2;
        for(int i=0;i<adj[c].size();i++) if(adj[c][i]==d) i1=i;
        for(int i=0;i<adj[d].size();i++) if(adj[d][i]==c) i2=i;
        
        adj[c].erase(adj[c].begin()+i1);
        adj[d].erase(adj[d].begin()+i2);
        
        vector<int>vis(V+1,0);
        dfs(c,vis,adj);
        
        if(!vis[d]) return 1;
        
        return 0;
    }
