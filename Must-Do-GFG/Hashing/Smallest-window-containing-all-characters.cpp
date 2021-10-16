/*
Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  
Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

Input:
S = "timetopractice"
P = "toc"
Output: 
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.

Solution:                                                                                                                                                  */
    string smallestWindow (string s, string p)
    {
        // Your code here
        int m1[256]={0};
        int m2[256]={0};
      
       
       int x=-1,c=0,m=INT_MAX,start=0;
       
        for(int i=0;i<p.length();i++){
            m2[p[i]]++;
        }   
        
        
        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
            if(m1[s[i]]<=m2[s[i]])  c++;
            
            if(c==p.length()){
                while(m1[s[start]] > m2[s[start]] || m2[s[start]]==0){
                    if(m1[s[start]] > m2[s[start]]) m1[s[start]]--;
                    start++;
                }
                
                if(m>i-start+1){
                    m=i-start+1;
                    x=start;
                }
            } 
        }
       if(x==-1) return "-1";
       return(s.substr(x,m));
        
    }
