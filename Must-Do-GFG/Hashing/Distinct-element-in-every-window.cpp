/*
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.
Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.

Solution:                                                                                                                                       */
   vector <int> countDistinct (int a[], int n, int k)
    {
        //code here.
        vector<int> v;
        unordered_map<int,int>mp;
        int c=0;
        for(int i=0;i<k;i++){
            if(!mp[a[i]])  c++;
            mp[a[i]]++;
        }
        v.push_back(c);
        int j=0;
        for(int i=k;i<n;i++){
           mp[a[j]]--;
           if(!mp[a[j]])  c--;
           if(!mp[a[i]])   c++;
           mp[a[i]]++;
           
           v.push_back(c);
           j++;
        }
        
        return v;
    }
