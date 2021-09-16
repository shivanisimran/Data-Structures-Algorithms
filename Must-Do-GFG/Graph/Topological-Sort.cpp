/*
Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.

Solution: Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, 
          vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
          
CODE:                                                                                                                              */
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto j: adj[i])
	            indegree[j]++;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    vector<int> ans;
	    while(!q.empty()){
	        int k=q.front();
	        ans.push_back(k);
	        q.pop();
	        for(auto i: adj[k]){
	            indegree[i]--;
	            if(indegree[i]==0) q.push(i);
	        }
	    }
	    return ans;
	}
