/*
Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Solution:                                                                                                                     */
string removeDuplicateLetters(string s) {
        string ans;
        stack<char> st;
        map<char,int>mp;
        map<char,bool> b;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]--;
            while(!b[s[i]] && !st.empty() && s[i]<st.top() && mp[st.top()]>0){
                b[st.top()]=0;
                st.pop();
            }
            
            if(!b[s[i]])
                st.push(s[i]);
            b[s[i]]=1;
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
            
    }
