/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.

Solution: Using the Prefix sum to calculate whehter sum upto ith element is repeating or not . If it is repeating then the there is a subarray with zero sum.
          
CODE:                                                                                                                               */
   int maxLen(vector<int>&a, int n)
    {   
        // Your code here
        int p=0;
        unordered_map<int,vector<int>>mp;
        mp[0].push_back(0);
        for(int i=0;i<n;i++){
            p+=a[i];
            mp[p].push_back(i+1);
        }
        int ans=0;
        for(auto i:mp){
            int k=i.second.size();
            if(i.second[k-1]-i.second[0]>ans)   ans=i.second[k-1]-i.second[0];
        }
        
        return ans;
    }
