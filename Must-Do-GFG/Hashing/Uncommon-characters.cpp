/*
Given two strings A and B. Find the characters that are not common in the two strings.
Input:
A = geeksforgeeks
B = geeksquiz
Output: fioqruz
Explanation: 
The characters 'f', 'i', 'o', 'q', 'r', 'u','z' 
are either present in A or B, but not in both.

Solution:                                                                                                                                */
        string UncommonChars(string a, string b)
        {
            // code here
            unordered_map<char,int>m1,m2;
            string s;
            for(int i=0;i<a.length();i++)   m1[a[i]]++;
            for(int i=0;i<b.length();i++)   m2[b[i]]++;
            
            for(int i=0;i<a.length();i++){
                if(!m2[a[i]]){
                    s.push_back(a[i]);
                    m2[a[i]]=1;
                } 
                
            }
            for(int i=0;i<b.length();i++){
                if(!m1[b[i]]){
                    m1[b[i]]=1;
                    s.push_back(b[i]);
                } 
               
            }
            
            if(s.empty())   s+="-1";
            else    sort(s.begin(),s.end());
            return s;
        }
