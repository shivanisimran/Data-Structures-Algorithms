/*
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.

Solution:                                                                                                                                                    */
class Solution 
{
    public:
    
    static bool comp(pair<int,int>&a, pair<int,int>&b){
       return (a.first < b.first) ;
    }
    
    int c=0;
    void dfs(int i,vector<pair<int,int>>&v, vector<int>&vis){
    
	    if(!vis[v[i].second]){
	        vis[v[i].second]=1;
	        vis[i]=1;
    	    c++;
    	    dfs(v[i].second,v,vis);
	    }
	  //  else return;
	    
    }
  
  //Function to find the minimum number of swaps required to sort the array.
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>>v;
	    
	    for(int i=0;i<nums.size();i++) v.push_back({nums[i],i});
	    
	    sort(v.begin(),v.end(),comp);
	    vector<int> vis(1000001,0);
	    
	    for(int i=0;i<nums.size();i++){
	        if(!vis[i] && v[i].second != i)  dfs(i,v,vis);
	    }
	    
	    return c;
	}
};
