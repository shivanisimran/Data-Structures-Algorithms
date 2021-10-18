/*
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Solution:                                                                                                                                          */
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<ll,int>mp;
        ll s=0,ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            s+=arr[i];
            mp[s]++;
        }
        for(auto i: mp){
            int z=i.second;
            z--;
            ans+= z*(z+1)/2;
        }
        return ans;
    }
