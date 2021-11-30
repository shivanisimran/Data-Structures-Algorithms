/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Solution:                                                                                                                    */
    unordered_map<int,int>par,rank;
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

    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)  return 0;
     
        for(int i:nums) {
             par[i]=i;
             rank[i]=0;
        } 
        unordered_set<int>st;
        for(int i:nums) st.insert(i);
        
        unordered_map<int,int>mp,p;
       
        for(int k:st)   p[k]=1;   
        for(int i:st)  if(p[i-1]) uni(i,i-1); 
             
        
        for(int k:st) mp[findpr(k)]++;
        int m=0;
        for(int k:st) if(mp[findpr(k)]>m) m=mp[findpr(k)];
        
        return m;
        
    }
