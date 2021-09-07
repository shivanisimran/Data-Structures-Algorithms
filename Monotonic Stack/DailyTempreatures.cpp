/*
Given an array of integers temperatures represents the daily temperatures, return an array answer 
such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example :
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Solution: Since the temperature values are not unique, so, insted of the values, we would push their indexes to our monotonic stack. 
CODE:                                                                                      */
 vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        stack<int> st;
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++){
           while(!st.empty() && t[st.top()]<t[i])  {
               ans[st.top()]=i-st.top();
               st.pop();
           }
            st.push(i);
        }
        return ans;
    }
