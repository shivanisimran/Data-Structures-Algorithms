/*
Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph..

Solution:                                                                                                         */
vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    bool visited[V];
	    for(int i=0;i<V;i++) 
	         visited[i]=false;
	    vector<int> v;
	    dfs (V,0,adj,v,visited);
	    return v;
	}
	void dfs(int V,int x,vector<int> adj[],vector<int>& v,bool visited[]){
	    v.push_back(x);
	    visited[x]=true;
	    for(int j=0;j<adj[x].size();j++){
	       if(!visited[adj[x][j]])
	           dfs(V,adj[x][j],adj,v,visited) ;  
	    }
	}
