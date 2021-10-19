/*
Given an array of integers A[] of size N and a sum B, find all unique combinations in A where the sum is equal to B. Each number in A may only be used once in the combination.

Note:
   All numbers will be positive integers.
   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
   The combinations themselves must be sorted in ascending order.
   
N = 7
A = {9, 1, 2, 7, 6, 1, 5}
B = 8
Output: (1 1 6)(1 2 5)(1 7)(2 6)
Explaination: These are the only possible 
combinations for getting sum 8.

Solution:                                                                                                                                               */
    set<vector<int>>st;
    vector<vector<int>> combinationSum(vector<int> &a, int n, int b){
        // code here
        vector<int> v;
        vector<vector<int>>ans;
        back(0,a,n,b,v);
        for(auto j: st)  ans.push_back(j);
        return ans;
    }
    
    void back(int x,vector<int>&a,int n,int b,vector<int>v){
        //if()
        if(b<0) return;
        if(b==0){
            sort(v.begin(),v.end());
            st.insert(v);
            return;
        }
        
        for(int i=x;i<n;i++){
            v.push_back(a[i]);
            back(i+1,a,n,b-a[i],v);
            v.pop_back();
        }
       
    }
