/*
You have n  tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

Solution:                                                                                                                     */
    set<string>st;
    int numTilePossibilities(string til) {
        for(int i=0;i<til.length();i++){
            back(til,i,"");
        }
        return st.size();
    }
    void back(string& til,int i,string str){
        int n=til.length();
       if(i>=0 && i<n && til[i]!='#' ){
           str+=til[i];
           st.insert(str);
           
           char c=til[i];
           til[i]='#';
           for(int j=0;j<n;j++){
               back(til,i+j,str);
               back(til,i-j,str);
           }
           til[i]=c;
       }
    }
