/*
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of graph 
and returns a boolean value true if graph is bipartite otherwise returns false.

Solution:                                                                                                                    */
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            if(dfs(i,-1,adj,vis,1)==false) 
	                return false;
	        }
	    }
	  
	    return true; 
	}
	bool dfs(int x,int parent,vector<int> adj[],vector<int>& vis,int col){
	    vis[x]=col;
	    for(int i: adj[x]){
	        if(vis[i]==0){
	            if(dfs(i,x,adj,vis,3-col)==false)
	                return false;
	        }
	        else if(i!=parent && vis[i]==col)
	            return false;
	    }
	    return true;
	}
