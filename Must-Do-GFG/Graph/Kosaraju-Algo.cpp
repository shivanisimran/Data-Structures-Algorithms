/*
Strongly Connected Components (Kosaraju's Algo) 
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

Solution: First we would do DFS traversal, starting from any node, to find the topological order and, will store the nodes in a stack.
          Then, we will start DFS traversal from top of node in a graph which is transpose of the given graph, i.e., egdes in reverse direction
          and find no. of connected components, which is given by the no. of unvisited nodes during DFS.
          
          
CODE:                                                                                                                                                     */
int kosaraju(int V, vector<int> adj[])
    {
        //code here
         vector<int> t[5000];
         for(int i=0;i<V;i++){
             for(int j=0;j<adj[i].size();j++){
                 t[adj[i][j]].push_back(i);
             }
         }
         int c=0;
         stack<int> st;
         vector<bool>vis(V,false);
         vector<bool>vis2(V,false);
         for(int i=0;i<V;i++){
             if(!vis[i]){
                 dfs(i,adj,st,vis);
             }
         }
         while(!st.empty()){
            if(!vis2[st.top()]){
                c++;
                dfs1(st.top(),t,vis2);
            }
            st.pop();      
         }
         return c;
    }
    
    void dfs(int x,vector<int> adj[],stack<int>& st,vector<bool>& visited){
	    visited[x]=true;
	    for(int j=0;j<adj[x].size();j++){
	       if(!visited[adj[x][j]])
	            dfs(adj[x][j],adj,st,visited) ; 
	    }
	    st.push(x);
	}
	
	void dfs1(int x,vector<int> t[],vector<bool>& vis2){
	    vis2[x]=true;
	    for(int j=0;j<t[x].size();j++){
	       if(!vis2[t[x][j]])
	            dfs1(t[x][j],t,vis2) ; 
	    }
	   
	}
          
