/*
Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.

Example :
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Solution:                                                                                                               */
string removeKdigits(string nums, int k) {
        stack<char> st;
        int n=nums.size();
        if(k==n)
            return "0";
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[i]<st.top() && st.size()+n-i>n-k)
                st.pop();
            st.push(nums[i]);
        }
        string s="";
        while(!st.empty()){
             s+=st.top();
            st.pop();
        }
       
        reverse(s.begin(),s.end()) ;
        string ans="";
        for(int i=0;i<n-k;i++){
            if(ans.length()==0 && s[i]=='0')
                continue;
            if(s[i])
              ans+=s[i];
        }
       if(ans.length()==0)
           return "0";
       return ans;
        
    }
