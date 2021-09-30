/*
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network 
where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, 
and place them between any pair of disconnected computers to make them directly connected. 
Return the minimum number of times you need to do this in order to make all the computers connected. 
If it's not possible, return -1. 

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.

Solution:                                                                                                                         */
      int makeConnected(int n, vector<vector<int>>& con) {
        if(con.size()<n-1)  return -1;
        vector<int> vis(n,false);
        vector<int> adj[n];
        for(int i=0;i<con.size();i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(n,i,vis,adj);
            }
        }
        return c-1;
    }

    void dfs(int n,int x,vector<int>& vis,vector<int> adj[]){
        vis[x]=true;
        for(auto i:adj[x]){
            if(!vis[i]) dfs(n,i,vis,adj);
        }
    }
