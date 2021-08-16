/*
Complete the function nextLargerElement() that takes list of integers arr[ ] and N as input parameters and 
returns list of integers of length N denoting the next greater elements for all the corresponding elements in the input array.

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1

Solution:                                                                                                            */
vector<long long> nextLargerElement(vector<long long> a, int n){
        // Your code here
        stack<long long> st;
        vector<long long> v(n,-1);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[a[i]]=i;     
        }
        for(int i=0;i<n;i++){
            if(st.empty())
                 st.push(a[i]);
            while(!st.empty() && a[i]>st.top()){
                v[mp[st.top()]]=a[i];
                st.pop();
            }
            st.push(a[i]);
        }
        return v;
    }
