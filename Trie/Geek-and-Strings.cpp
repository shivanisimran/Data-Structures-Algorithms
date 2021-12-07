/*
Geek has a list Li containing (not necessarily distinct) N words and Q queries. 
Each query consists of a string x. For each query, find how many strings in the List Li has the string x as its prefix.

nput: 
N = 5, Q = 5
li[] = {'abracadabra', 'geeksforgeeks', 
      'abracadabra', 'geeks', 'geeksthrill'}
query[] = {'abr', 'geeks', 'geeksforgeeks', 
         'ge', 'gar'}

Output: 2 3 1 3 0

Solution:                                                                                                                                                 */
class Solution{
public:
    struct Trie{
        int val=0;
        Trie* children[26];
    };
    
    void insert(Trie* root ,string s){
        Trie* curr=root;
        for(char i: s){
            if(!curr->children[i-'a'])   curr->children[i-'a']=new Trie();
            curr=curr->children[i-'a'];
            curr->val+=1;
        }

    }
    int search(Trie* root ,string s){
        Trie* curr=root;
        int c=0;
        for(char i: s){
            if(!curr->children[i-'a'])   return 0;
            else{
                curr=curr->children[i-'a'];
            }
        }
       return curr->val;
    }
    
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        Trie* root=new Trie();
        for(int i=0;i<N;i++)  insert(root,li[i]);
        
        vector<int> v;
        for(int i=0;i<Q;i++){
            v.push_back(search(root,query[i]));
        }
        return v;
    }
};

