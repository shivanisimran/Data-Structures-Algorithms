/*
 Your task is to complete the function dijkstra()  which takes number of vertices V and an adjacency list adj as input parameters and returns a list of integers, 
 where ith integer denotes the shortest distance of the ith node from Source node. Here adj[i] contains a list of lists containing two integers 
 where the first integer j denotes that there is an edge between i and j and second integer w denotes that the weight between edge i and j is w.
 
Solution:                                                                                                                  */
   vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int>ans(v,INT_MAX);
        ans[s]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,s});
        while(!pq.empty()){
            auto k=pq.top();
            pq.pop();
            for(auto i:adj[k.second]){
                int j=i[0],w=i[1];
                if(ans[j] > k.first+w){
                    ans[j]=(k.first+w);
                    pq.push({ans[j], j});
                }
                
            } 
        }
        return ans;
    }
