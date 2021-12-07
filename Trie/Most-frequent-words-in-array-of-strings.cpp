/*
Given an array arr containing N words consisting of lowercase characters. Your task is to find the most frequent word in the array. 
If multiple words have same frequency, then print the word whose first occurence occurs last in the array as compared to the other strings with same frequency.

Input:
N = 3
arr[] = {geeks,for,geeks}
Output: geeks
Explanation: "geeks" comes 2 times.

Solution:                                                                                                                                                        */
class Solution
{
    public:
    //Function to find most frequent word in an array of strings.
    int m=0;
    string ans;
    struct Trie{
        int val;
        string key;
        Trie* children[26];
    };
    
    void insert(Trie* root ,string s){
        Trie* curr=root;
        int x=31;
        //int k=x^INT_MAX;
        for(auto i:s){
            if(!curr->children[i-'a'])   curr->children[i-'a']=new Trie();
            curr=curr->children[i-'a'];     
        }
        curr->key=s;
        curr->val+=1;
        if(curr->val > m){
            m=curr->val;
            ans=curr->key;
        }
    }
    
    string mostFrequentWord(string arr[], int n) 
    {
        // code here
        Trie* root = new Trie();
        for(int i=n-1;i>=0;i--)  insert(root,arr[i]);
        for(int i=0;i<n;i++){
            
        }
        return ans;
    }
};
