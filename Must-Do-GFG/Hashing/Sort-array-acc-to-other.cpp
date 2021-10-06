/*
Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ] such that 
all the relative positions of the elements in the first array are the same as the elements in the second array A2[ ].
See example for better understanding.
Note: If elements are repeated in the second array, consider their first occurance only.

Input:
N = 11 
M = 4
A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
A2[] = {2, 1, 8, 3}
Output: 
2 2 1 1 8 8 3 5 6 7 9
Explanation: Array elements of A1[] are
sorted according to A2[]. So 2 comes first
then 1 comes, then comes 8, then finally 3
comes, now we append remaining elements in
sorted order.

Solution:                                                                                                                              */
    vector<int> sortA1ByA2(vector<int> a1, int n, vector<int> a2, int m) 
    {
        //Your code here
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)    mp[a1[i]]++;
        vector<int>v;
        for(int i=0;i<m;i++){
            int f=mp[a2[i]];
            while(f--)  v.push_back(a2[i]);
            mp[a2[i]]=0;
        }
        int x=v.size();
        for(int i=0;i<n;i++){
            if(mp[a1[i]]!=0){
                v.push_back(a1[i]);
            }
        }
        sort(v.begin()+x,v.end());
        return v;
        
    } 
