/*
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.


Example :
Input: arr = [4,3,2,1,0]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.

Solution: The basic idea is to use increasing Stack to keep track of the max value until the current position, and compare it to the sorted array. 
          If the top of stack equals the element at index i in the sorted array, then the final count++.     
CODE:                                                                                                              */
int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        int c=0;
        for(int i=0;i<arr.size();i++){
            if(st.empty() || arr[i]>st.top())
                st.push(arr[i]);
            if(st.top()==i)
                c++;
        }
        return c;
    }


/* Another version of the problem:
You are given an integer array arr.
We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
Return the largest number of chunks we can make to sort the array.

Example :
Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.

Solution:                                                                                                */
int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            v.push_back(arr[i]);
        }
        sort(v.begin(),v.end());
        stack<int> st;
        long long c=0,s1=0,s2=0;
        for(int i=0;i<n;i++){
            s1+=v[i];
            s2+=arr[i];
            if(st.empty() || arr[i]>st.top())
                st.push(arr[i]);
            
            //since elements can be repeating so, we will also keep track of the sum upto current index in original array and the sorted array.      
            if(st.top()==v[i] && s1==s2) {
                    c++; 
            }
           
        }
        return c;
    }
