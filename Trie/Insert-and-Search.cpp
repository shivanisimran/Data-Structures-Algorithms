/*
Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. 
Your task is to use TRIE data structure and search the given string A. 
If found print 1 else 0.

Input:
N = 8
key[] = {the,a,there,answer,any,by,
         bye,their}
search = the
Output: 1
Explanation: the is present in the given
string "the a there answer any by bye
their"

Solution:                                                                                                                                                    */

void insert(struct TrieNode *root, string key)
{
    // code here
    TrieNode *curr=root;
    for(int i=0;i<key.length();i++){
        if(!curr->children[key[i]-'a'])
             curr->children[key[i]-'a'] = new TrieNode();
        curr=curr->children[key[i]-'a'];
    }
    curr->isLeaf=true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    // code here
    TrieNode *curr=root;
    for(int i=0;i<key.length();i++){
        if(!curr->children[key[i]-'a'])  return false;
    
        curr=curr->children[key[i]-'a'];
    }
    return (curr->isLeaf);
    
}
