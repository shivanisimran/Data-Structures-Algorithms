/*
Given a Directed Graph having V nodes numbered from 1 to V, and E directed edges. Given two nodes, source and destination, 
count the number of ways or paths between these two vertices in the directed graph. These paths should not contain any cycle.
Note: Graph doesn't contain multiple edges, self-loop, and cycles.

Solution:                                                                                                                                                    */
    int c=0;
    void dfs(int x,int d,vector<int> adj[]){
        if(x==d) c++;
        for(int i=0;i<adj[x].size();i++) {
            dfs(adj[x][i],d,adj);
        }
    }
    
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int v, vector<int> adj[], int s, int d) {
        // Code here
        dfs(s,d,adj);
        return c;
    }
