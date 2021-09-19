/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, 
for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.

Solution: It is possible if there is no cycle in the graph. Otherwise, not possible.
          So, this question becomes same as detecting cycle in directed graph.

CODE:                                                                                                                                    */
bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> adj[10000];
	    for(int i=0;i<pre.size();i++)
	        adj[pre[i].first].push_back(pre[i].second);
	        
	    vector<bool>vis(N,false);
	    vector<bool>st(N,false);
	    
	    for(int i=0;i<N;i++){
	        if(!vis[i])
	            if(dfs(i,adj,vis,st))  return false;
	    }
	    return true;
	}

	bool dfs(int x,vector<int> adj[],vector<bool> &vis,vector<bool> &st){
	    vis[x]=true;
	    st[x]=true;
	    for(auto i:adj[x]){
	        //cout<<i<<" ";
	        if(!vis[i]){
	            if(dfs(i,adj,vis,st))  return true;
	        }
	        else if(st[i]) return true;
	    }
	    st[x]=false;
	    return false;
	    
	}

