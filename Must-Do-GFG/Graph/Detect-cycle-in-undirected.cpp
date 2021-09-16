/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

Solution: (Using DFS):                                                                                      */
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
	    vector<bool> vis(V,false);
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	            if(dfs (i,-1,adj,vis)) return true;
	    }
	    return false; 
    }

    bool dfs(int x,int parent,vector<int> adj[],vector<bool> vis){
	    vis[x]=true;
	    for(auto i: adj[x]){
	        if(!vis[i]){
	            if(dfs(i,x,adj,vis))
	                 return true;
	        }
	        else if(i!=parent)
	            return true;
	    }
	    return false;
	}
