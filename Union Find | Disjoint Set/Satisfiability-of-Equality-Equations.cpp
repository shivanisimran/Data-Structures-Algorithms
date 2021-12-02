/*
You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 
and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

Solution:                                                                                                                                                           */
    unordered_map<char,char>par;
    unordered_map<char,int>rank;

    char findpr(char x){
        if(par[x]==x)    return x;
        return par[x]=findpr(par[x]);
    }
    
    void uni(char u,char v){
        u=findpr(u);
        v=findpr(v);
        
        if(rank[u]>rank[v])  par[v]=u;
        else if(rank[u]<rank[v])    par[u]=v;
        
        else{
            par[u]=v;
            rank[v]++;
        }      
    }
    
    bool equationsPossible(vector<string>& eq) {
        for(char i='a';i<='z';i++){
            rank[i]=0;
            par[i]=i;
        }
        
        for(auto k: eq){
            if(k[1]=='=') uni(k[0],k[3]);
        }
        
        for(auto k: eq){
            if(k[1]=='!' && findpr(k[0])==findpr(k[3])) return false;
        }
        
        return true;
    }
