/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Solution:  First, we check, whether the graph contains cycle or not.
           If it doesn't contain cycle, we would topologically sort it.
           
CODE:                                                                                                                           */
vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> ans;
        
        vector<int>adj[n];
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        vector<bool> vis(n,false);
        vector<bool> st(n,false);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,st))  return ans;
            }
        }
       
       
        vector<int>in(n,0);
        for(int i=0;i<n;i++){
             for(auto j:adj[i]){
                   in[j]++;
             }       
        }
       
       
          queue<int> q;
          for(int i=0;i<n;i++){
             if(in[i]==0)
                q.push(i);
          }
          while(!q.empty()){
              int k=q.front();
              q.pop();
              ans.push_back(k);
              for(auto i:adj[k]){
                  in[i]--;
                  if(in[i]==0)  q.push(i);

              }
          }

        return ans;
    }
    

    bool dfs(int x,vector<int> adj[],vector<bool>& vis,vector<bool>& st){
        vis[x]=true;
        st[x]=true;
        for(auto i: adj[x]){
            if(!vis[i]){
                if(dfs(i,adj,vis,st))  return true;
            }
            else if(st[i])  return true;
        }
        st[x]=false;
        return false;
    }
