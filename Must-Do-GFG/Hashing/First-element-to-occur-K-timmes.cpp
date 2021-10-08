/*
Given an array of N integers. Find the first element that occurs K number of times. 
Input :
N = 7, K = 2
A[] = {1, 7, 4, 3, 4, 8, 7}
Output :
4
Explanation:
Both 7 and 4 occur 2 times. 
But 4 is first that occurs 2 times.

Solution:                                                                                                                           */
   int firstElementKTime(int a[], int n, int k)
    {
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[a[i]]++;
            if(mp[a[i]]==k) return a[i];
        }
        return -1;
    }
