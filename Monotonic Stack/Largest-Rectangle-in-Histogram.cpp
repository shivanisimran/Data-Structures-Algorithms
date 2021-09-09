/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Example:
Input: heights = [2,1,5,6,2,3]
Output: 10

Solution: The idea is to find the next smaller element in left and in right for every element. 
          Thus for every element, we get width upto which no smaller height element lies.
          Then, find that area. We will do it for all elements, and return the maximum area.
          
CODE:                                                                                                               */
int largestRectangleArea(vector<int>& ht) {
        int n=ht.size();
          vector<int> l;
          vector<int> r;
        for(int i=0;i<n;i++){
            l.push_back(i);
            r.push_back(n-i-1);
        }
       
        //finding next smaller element in right.
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && ht[st.top()]>ht[i]){
                r[st.top()]=i-st.top()-1;
                st.pop();
            }
            st.push(i);     
        }
  
        //finding next smaller element in left.
        stack<int> s1;
        for(int i=n-1;i>=0;i--){
            while(!s1.empty() && ht[s1.top()]>ht[i]){
                l[s1.top()]=s1.top()-i-1;
                s1.pop();
            }
            s1.push(i);  
        }
        int x=0;
        for(int i=0;i<n;i++){
            x=max(x, (ht[i]*(l[i]+r[i]+1)));
        }
        
        return x;
    }
