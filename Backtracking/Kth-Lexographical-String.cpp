/*
A happy string is a string that:
consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

Solution:                                                                                                                                    */
    vector<string>v;
    string getHappyString(int n, int k) {
        string s="abc";
        for(int i=0;i<3;i++)
            back(i,s,n,"");
        if(k>v.size())   return "";
        sort(v.begin(),v.end());
        return (v[k-1]);
        
    }
    void back(int x,string s,int n,string str){
         if(x>=0 && x<3 && s[x]!='#'){
             str+=s[x];
             
             if(str.size()==n){
                v.push_back(str);
                 return;
             }
             
             for(int i=1;i<3;i++){
                 back(x+i,s,n,str);
                 back(x-i,s,n,str);
             }
             
         }
        else return;
    }
