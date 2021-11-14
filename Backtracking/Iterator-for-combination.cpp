/*
Design the CombinationIterator class:

CombinationIterator(string characters, int combinationLength) Initializes the object with a string characters of sorted distinct 
lowercase English letters and a number combinationLength as arguments.

next() Returns the next combination of length combinationLength in lexicographical order.

hasNext() Returns true if and only if there exists a next combination.

Input
["CombinationIterator", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[["abc", 2], [], [], [], [], [], []]
Output
[null, "ab", true, "ac", true, "bc", false]

Explanation
CombinationIterator itr = new CombinationIterator("abc", 2);
itr.next();    // return "ab"
itr.hasNext(); // return True
itr.next();    // return "ac"
itr.hasNext(); // return True
itr.next();    // return "bc"
itr.hasNext(); // return False

Solution:                                                                                                                                                   */
    vector<string> v;
    void back(int x,string c,int k,string chars){
        if(x>chars.size()) return;
        if(c.length()==k){
            v.push_back(c);
            return;
        }
       
        for(int i=x;i<=chars.size();i++){
           c.push_back(chars[i]);
           back(i+1,c,k,chars) ;
           c.pop_back();
        }
    }
    
    CombinationIterator(string chars, int k) {
        string c;
        back(0,c,k,chars);

    }
    
    int c=0;  
    string next() { 
       return v[c++];  
    }
    
    bool hasNext() {
        if(c<v.size()) return true;
        return false;
    }
