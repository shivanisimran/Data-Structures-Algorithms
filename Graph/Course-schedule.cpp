/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Solution:  If it contains cycle then false, else true.
CODE:                                                                                                               */
bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool> vis(n,false);
        vector<bool> st(n,false);
        vector<int>adj[n];
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,st))  return false;
            }
        }
        return true;
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
