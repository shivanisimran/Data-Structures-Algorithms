/*
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. 
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. 
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]

Solution:                                                                                                                                                   */
    int par[100001];
    int rank[100001];
    
    int findpr(int x){
        if(par[x]==x)    return x;
        return par[x]=findpr(par[x]);
    }
    
    void uni(int u,int v){
        u=findpr(u);
        v=findpr(v);
        
        if(rank[u]>rank[v])  par[v]=u;
        else if(rank[u]<rank[v])    par[u]=v;
        
        else{
            par[u]=v;
            rank[v]++;
        }      
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& ed) {
        for(int i=0;i<=1000;i++) {
             par[i]=i;rank[i]=0;
        }  
        for(int i=0;i<ed.size();i++){
            if(findpr(ed[i][0])==findpr(ed[i][1]))    return{ed[i][0],ed[i][1]};
            else uni(ed[i][0],ed[i][1]);
        }
        return {0,0};
    }
 
