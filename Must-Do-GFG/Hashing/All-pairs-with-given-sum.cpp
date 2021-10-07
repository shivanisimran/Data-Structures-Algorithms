/*
Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.
Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.

Solution:                                                                                                                         */
    vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int k)
     {
        // Your code goes here   
        vector<pair<int,int>>v;
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++){
            mp[b[i]]++;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            if(mp[k-a[i]])  v.push_back({a[i],k-a[i]});
        }
        
        return v;
     }
