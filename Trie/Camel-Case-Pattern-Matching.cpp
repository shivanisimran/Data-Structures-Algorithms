/*
Given a dictionary of words where each word follows CamelCase notation, 
print all words in the dictionary that match with a given pattern consisting of uppercase characters only.

CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. 
Common examples include: “PowerPoint” and “WikiPedia”, “GeeksForGeeks”, “CodeBlocks”, etc.

Input:
N=3
Dictionary=["WelcomeGeek",
"WelcomeToGeeksForGeeks","GeeksForGeeks"]
Pattern="WTG"
Output:
WelcomeToGeeksForGeeks
Explanation:
Since only WelcomeToGeeksForGeeks matches 
the pattern, it is the only answer.

Solution:                                                                                                                                        */
    struct Trie{
        bool last;
        Trie* children[26];
    };
    
    void insert(Trie* root ,string s){
        Trie* curr=root;
        for(char i: s){
            if(!curr->children[i-'A'])   curr->children[i-'A']=new Trie();
            curr=curr->children[i-'A'];
        }
        curr->last=true;
    }
    
    bool search(Trie* root ,string s){
        Trie* curr=root;
        int c=0;
        for(char i: s){
            if(i>='A' && i<='Z'){
                if(!curr->children[i-'A'])   return false;
                else  curr=curr->children[i-'A'];
                
                if(curr->last) return true;
            }
        }
       return curr->last;
    }
    vector<string> CamelCase(int N, vector<string> Dict, string Pat) {
        // code here
      
        Trie* root=new Trie();
        insert(root,Pat);
        vector<string> ans;
        vector<pair<string,pair<string,int>>> v;
        for(int i=0;i<N;i++){
            string temp="";
           
            for(int j=0;j<Dict[i].length();j++) 
                if(Dict[i][j]>='A' && Dict[i][j]<='Z')  temp+=Dict[i][j];
          
            if(search(root, Dict[i])) v.push_back({temp, {Dict[i],i}});
        }
        
       //ans is to be sorted acc to capital lettes. If that is same then, acc to their position in input array.
        sort(v.begin(),v.end(),[](pair<string,pair<string,int>>& a, pair<string,pair<string,int>>& b){
            if(a.first == b.first)  return a.second.second < b.second.second;
            return(a.first < b.first);
        });
        
       for(auto i: v) ans.push_back(i.second.first);
       return ans; 
    }
