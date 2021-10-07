/*
Given a string str and another string patt. Find the first position (considering 0-based indexing) of the character in patt that is present at the minimum index in str.
Input:
str = geeksforgeeks
patt = set
Output: 1
Explanation: e is the character which is
present in given patt "geeksforgeeks"
and is first found in str "set". First Position
of e in str is 1. 

Solution:                                                                                                                            */
    int minIndexChar(string str, string patt)
    {
        // Your code here
        unordered_map<char,int>mp;
        for(int i=0;i<patt.size();i++){
            mp[patt[i]]++;
        }
        for(int i=0;i<str.size();i++){
            if(mp[str[i]]) return i;
        }
        return -1;
    }
