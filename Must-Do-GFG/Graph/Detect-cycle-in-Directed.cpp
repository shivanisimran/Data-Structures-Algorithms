/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.

Solution: (Using DFS):                                                                                             */
     bool isCyclic(int V, vector<int> adj[]) {
        // Code here
	    vector<bool> vis(V,false);
	    vector<bool> st(V,false);
	    for(int i=0;i<V;i++){
	        if(!vis[i])
	            if(dfs (i,st,adj,vis)) return true;
	    }
	    return false; 
    }

    bool dfs(int x,vector<bool> &st,vector<int> adj[],vector<bool> &vis){
	    vis[x]=true;
	    st[x]=true;
	    for(auto i: adj[x]){
	        if(!vis[i]){
	            if(dfs(i,st,adj,vis))  return true;
	        }
	        else if(st[i]==true) return true;
	    }
	    st[x]=false;
	    return false;
	}
