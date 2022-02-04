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


# **Similar Problems:**

/* 
Longest Sub-Array with Sum K:

Given an array containing N integers and an integer K., 
Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.

Solution:                                                                                                                            */
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        unordered_map<int,int> mp;
        mp[0]=0;
        int s=0,ans=0;
        for(int i=0;i<n;i++){
            s+=a[i];
            if(s==k)  ans=i+1;
            
            if(!mp[s]) mp[s]=i+1;
            
            if(mp[s-k]>0) ans=max(ans,i+1-mp[s-k]);
        }
        return ans;
    } 

/*

Contiguous Array:

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Solution:                                                                                                                                            */
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0]=0;
        int z=0,o=0,n=nums.size(),ans=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0)  z++;
            else    o++;
            
            if(!mp[z-o]) mp[z-o]=i+1;
            if(z-o==0)  ans=i+1;
            
           // cout<<(z-o)<<" "<<mp[z-o]<<endl;
            ans=max(ans,i+1-(mp[z-o]));
   
        }
        
        return ans;
    }
