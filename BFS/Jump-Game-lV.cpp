/*
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.

Solution:                                                                                                                                        */
    int minJumps(vector<int>& arr) {
         unordered_map<int,vector<int>>mp;
         unordered_map<int,int>vis;
         vector<int>d(arr.size());

         
        for(int i=1;i<arr.size();i++) mp[arr[i]].push_back(i);

        d[0]=0;
     
        queue<int>q;
        q.push(0);
        
        while(!q.empty()){
            int k=q.front();
            q.pop();
            vector<int>& adj=mp[arr[k]];
            
            if(k+1 < arr.size())  adj.push_back(k+1);
            if(k-1 >= 0)  adj.push_back(k-1);
            
            for(int i : adj){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                    d[i]=d[k]+1;
                }
                
            }
            
            mp[arr[k]].clear();
        }
        
      return d[arr.size()-1];
        
    }
 
