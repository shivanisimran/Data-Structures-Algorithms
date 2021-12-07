/*
Given an array of strings arr[] of size n and given s a string str and an integer k. 
The task is to find the count of strings in arr[] whose prefix of length k matches with the k length prefix of str.

Input:
n = 6
arr[] = {“abba”, “abbb”, “abbc”, “abbd”, 
“abaa”, “abca”}
str = “abbg”
k = 3
Output: 4 
Explanation:
“abba”, “abbb”, “abbc” and “abbd” are 
the matching strings.

Solution:                                                                                                                                       */
class Solution{   
public:
    struct Trie{
        Trie* children[26];
    };
    
    void insert(Trie* root ,string s){
        Trie* curr=root;
        for(char i: s){
            if(!curr->children[i-'a'])   curr->children[i-'a']=new Trie();
            curr=curr->children[i-'a'];
        }

    }
    int search(Trie* root ,string s){
        Trie* curr=root;
        int c=0;
        for(char i: s){
            if(!curr->children[i-'a'])   return c;
            else{
                c++;
                curr=curr->children[i-'a'];
            }
        }
       return c;
    }
    
    int klengthpref(string arr[], int n, int k, string str){  
        Trie* root=new Trie();
        insert(root,str);
        int ans=0;
        for(int i=0;i<n;i++){
            if(search(root,arr[i])>=k){
              //  cout<<arr[i]<<" ";
                ans++;
            } 
        }
        return ans;
    }
};
