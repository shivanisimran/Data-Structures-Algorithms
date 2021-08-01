/*
Complete the function dfsOfGraph() which takes the integer V denoting the number of vertices and adjacency list as input parameters
and returns  a list containing the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph. */

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
