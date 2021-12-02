/*
You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where 
meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. 
Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. 
This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, 
then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.
Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

Solution:                                                                                                                             */
    unordered_map<int,int>rank,par,vis;
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
   
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int f) {
        sort(meet.begin(),meet.end(), [](vector<int> &a, vector<int> &b){
        return a[2]<b[2];
        });
       
        for(auto k:meet){
            int a=k[0],b=k[1];
            par[a]=a,par[b]=b;
        }
        uni(0,f);
        int i=0;
        
        while(i<meet.size()){ 
            int x=meet[i][2],a,b;
            vector<int> v;
            
            while(i<meet.size() && meet[i][2]==x){
                a=meet[i][0],b=meet[i][1];
                v.push_back(a);
                v.push_back(b);
                uni(a,b);
                i++;
            }
            
            for(auto j: v) {
                if(findpr(j)!=findpr(0))  par[j]=j;
            }
            
        }
        
        vector<int>v;
        v.push_back(0);
        v.push_back(f);
        vis[0]=1;
        vis[f]=1;
        for(auto k:meet){
            int a=k[0],b=k[1];
            if(findpr(a)==findpr(f) && !vis[a]){
                v.push_back(a);
                vis[a]=1;
            } 
            if(findpr(b)==findpr(f) && !vis[b]){
                 v.push_back(b);
                vis[b]=1;
            }
        }
         
        return v;
        
    }
