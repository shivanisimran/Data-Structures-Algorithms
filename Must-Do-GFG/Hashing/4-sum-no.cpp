/*
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.
Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.

Solution:                                                                                                                                   */
     vector<vector<int> > fourSum(vector<int> &a, int k) {
        // Your code goes here
        int n=a.size();
        vector<vector<int>> v;
        sort(a.begin(),a.end());
        map<vector<int>,int>mp;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1,m=n-1;
                while(l<m){
                    if(a[i]+a[j]+a[l]+a[m]==k){
                        vector<int> x;
                        x={a[i],a[j],a[l],a[m]};
                        sort(x.begin(),x.end());
                        
                        if(!mp[x])  v.push_back(x);
                        mp[x]++;
                        l++;m--;
                    }
                    else if(a[i]+a[j]+a[l]+a[m] < k)    l++;
                    else    m--;
                }
                
            }
        }
        return v;
    }
