/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array. 
When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3

Solution:                                                                                                                                                       */
    vector<int>adj[100000];
    unordered_map<int,bool>vis;
    
    bool ans=false;
    void dfs(int x,vector<int>& arr){
        vis[x]=true;
        if(arr[x]==0) {
            ans=true;
            return;
        }
        for(auto k:adj[x])  if(!vis[k]) dfs(k,arr);
    }
    
    bool canReach(vector<int>& arr, int start) {
        
        for(int i=0;i<arr.size();i++){
            if(i+arr[i] < arr.size())    adj[i].push_back(i+arr[i]);
            if(i-arr[i] >= 0)   adj[i].push_back(i-arr[i]);
        }  
      
        dfs(start,arr);
        return ans;
    }
