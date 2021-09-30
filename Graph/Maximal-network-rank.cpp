/*
There is an infrastructure of n cities with some number of roads connecting these cities. 
Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

The network rank of two different cities is defined as the total number of directly connected roads to either city. 
If a road is directly connected to both cities, it is only counted once.
The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.

Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
Output: 4
Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.


Solution:                                                                                                                      */
    int maximalNetworkRank(int n, vector<vector<int>>& r) {
        if(r.size()==0) return 0;
        vector<int> adj[n];
        
         vector<int> d(n,0);
        for(int i=0;i<r.size();i++){
            adj[r[i][0]].push_back(r[i][1]);
            adj[r[i][1]].push_back(r[i][0]);
            
            d[r[i][0]]++;
            d[r[i][1]]++;
        }
        
       vector<int> v;
        
        for(int x=0;x<n-1;x++){
            for(int y=x+1;y<n;y++){
                if(find(adj[x].begin(),adj[x].end(),y) != adj[x].end())
                    v.push_back(d[x]+d[y]-1);
                else  v.push_back(d[x]+d[y]);
            }
        }
        return *max_element(v.begin(),v.end());
    }

 
