/*
Given an unsorted array of integers, find the number of continuous subarrays having sum exactly equal to a given number k.

Input:
N = 5
Arr = {10 , 2, -2, -20, 10}
k = -10
Output: 3
Explaination: 
Subarrays: arr[0...3], arr[1...4], arr[3..4]
have sum exactly equal to -10.

Solution:                                                                                                                                                              */
    int findSubArraySum(int arr[], int n, int k)
    {
        // code here
        unordered_map<int,int>mp;
        mp[0]=1;
        int s=0,ans=0;
        for(int i=0;i<n;i++){
            s+=arr[i];
            mp[s]++;
            ans+=mp[s-k];
        }
        return ans;
    }
