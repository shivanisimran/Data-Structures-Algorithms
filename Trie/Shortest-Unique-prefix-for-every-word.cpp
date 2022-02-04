/*
Given an array of words, find all shortest unique prefixes to represent each word in the given array. 
Assume that no word is prefix of another.

Input: 
N = 4
arr[] = {"zebra", "dog", "duck", "dove"}
Output: z dog du dov
Explanation: 
z => zebra 
dog => dog 
duck => du 
dove => dov 

Solution:                                                                                                                                            */
class Solution
{
    public:
    struct Trie{
        int count=0;
        Trie* children[26];
    };
    
    void insert(Trie* root ,string s){
        Trie* curr=root;
        for(char i: s){
            if(!curr->children[i-'a'])   curr->children[i-'a']=new Trie();
            curr=curr->children[i-'a'];
            curr->count = curr->count+1;
        }

    }
    string search(Trie* root ,string s,string& k){
        Trie* curr=root;
        int c=0;
        for(char i: s){
             k.push_back(i);
            if(curr->children[i-'a']->count > 1) {
               curr=curr->children[i-'a'];
            }
            else{
                return k;
            }
        }
       return k;
    }
    
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Trie* root=new Trie();
        vector<string> ans(n);
        for(int i=0;i<n;i++)    insert(root,arr[i]);
        
        for(int i=0;i<n;i++){
            string temp="";
            ans[i]=search(root,arr[i],temp);
        }
        return ans;
    }
    
};
