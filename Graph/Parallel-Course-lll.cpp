/*
You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations 
where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). 
Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses following these rules:

You may start taking a course at any time if the prerequisites are met.
Any number of courses can be taken at the same time.
Return the minimum number of months needed to complete all the courses.

Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).

Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
Output: 8
Explanation: The figure above represents the given graph and the time required to complete each course. 
We start course 1 and course 2 simultaneously at month 0.
Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
Thus, the earliest time we can start course 3 is at month 3, and the total time required is 3 + 5 = 8 

Solution: Topological sorting of courses according to dependencies                                                                                     */

     int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        vector<int>adj[50001];
        
        for(int i=0;i<rel.size();i++){
            adj[rel[i][0]].push_back(rel[i][1]);
        }
        
        vector<int>in(n+1,0);
        
        for(int i=1;i<=n;i++){
            for(auto j: adj[i]) in[j]++;
        }
        
        queue<int> q;
        
        vector<int> dist(n+1,0);
        //dist[i] stores min time needed to complete task i with all prequisites of i.
        for(int i=1;i<=n;i++){
            if(in[i]==0) {
                dist[i]=time[i-1];
                q.push(i);
            }
        } 
     
        
        while(!q.empty()){
            int k=q.front();
            q.pop();

            for(auto j: adj[k]){                      
                dist[j]=max(dist[j], dist[k]+time[j-1]);
                in[j]--;
                if(in[j] == 0)   q.push(j);
            }
        }
        
        return *max_element(dist.begin(),dist.end());
    }
