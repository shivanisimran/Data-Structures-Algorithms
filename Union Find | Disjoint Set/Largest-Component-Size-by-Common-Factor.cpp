/*
You are given an integer array of unique positive integers nums. Consider the following graph:

There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

Input: nums = [4,6,15,35]
Output: 4

Solution:                                                                                                                    */
    int par[100001];
    
    int findpr(int x){
        if(par[x]==x)    return x;
        return par[x]=findpr(par[x]);
    }
    
    void uni(int u,int v){
        u=findpr(u);
        v=findpr(v);
        
        if(u==v)    return;
        else{
            par[u]=v;
           
        }
        
        
    }
    
    int largestComponentSize(vector<int>& nums) {
     
        int x=*max_element(nums.begin(),nums.end());
        for(int i=1;i<=x;i++){
            par[i]=i;
        }
        unordered_map<int,int>mp;
        for(int k:nums){
            for(int i=2;i<=sqrt(k);i++){
                if(k%i==0){
                    uni(i,k);
                    uni(k,k/i);
                }                
            }
        }
        for(int k:nums){
            mp[findpr(k)]++;
        }    
            
        int m=0;
        for(int k:nums)  if(mp[findpr(k)]> m) m=mp[findpr(k)];
        
        return m;
        
    }
