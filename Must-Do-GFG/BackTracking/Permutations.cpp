/*
Given a string S. You have to find all permutations of the given string. You can return the permutations in any order, 
driver code will automatically sort the permutations in lexicographic increasing order.

Input:
ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB
BAGS BASG BGAS BGSA BSAG BSGA
GABS GASB GBAS GBSA GSAB GSBA
SABG SAGB SBAG SBGA SGAB SGBA

Solution:                                                                                                                                    */
    set<string>st;
    vector<string> permute(string s){
       // code here
       vector<string> v;
       for(int i=0;i<s.length();i++){
           back(s,i,"",s.length());
       }
       for(string i: st) v.push_back(i);
       return v;
    }

    void back(string s,int x,string str,int n){
        if(x>=0 && x<n && s[x]!='#'){
            str+=s[x];
            if(str.length()==n){
                 st.insert(str);
                 return;
            }   
            
            char c=s[x];
            s[x]='#';
            for(int i=1;i<n;i++){
                back(s,x+i,str,n);
                back(s,x-i,str,n);
            }
           
            s[x]=c;
        }
        else return;
   }
    
