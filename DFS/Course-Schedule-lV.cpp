/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where 
prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
Return a boolean array answer, where answer[j] is the answer to the jth query.

Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
Course 0 is not a prerequisite of course 1, but the opposite is true.

Solution:                                                                                                                                    */

    vector<int>adj[100];
    void dfs(int x,vector<int>& vis){
        vis[x]=1;
        for(auto j: adj[x]){
            if(!vis[j]) dfs(j,vis);
        }
    }

    vector<bool> checkIfPrerequisite(int n,vector<vector<int>>& pre,vector<vector<int>>& qr) {
      
        for(int i=0;i<pre.size();i++){
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        
        vector<bool> ans;
        
        for(auto q: qr){
            vector<int>vis(n,0);
            dfs(q[0],vis);
            ans.push_back(vis[q[1]]);
        }
        
       return ans;
    }
