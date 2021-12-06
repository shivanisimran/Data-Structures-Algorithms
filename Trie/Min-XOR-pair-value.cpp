/*
Given an array of integers of size N find minimum xor of any 2 elements.
Input:
N = 3
arr[] = {9,5,3}
Output: 6
Explanation: 
There are 3 pairs -
9^5 = 12
5^3 = 6
9^3 = 10
Therefore output is 6.

Solution:                                                                                                                             */
class Solution{   
public:
    struct Trie{
        int value;
        Trie* children[2];
    };
    
    
    
    void insert(Trie* root ,int n){
        Trie* curr=root;
        
        int x=31;
        while(x>=0){
            bool d = (n & (1 << x));
            
            if(curr->children[d] == NULL)   curr->children[d]=new Trie;
            curr=curr->children[d];
            
            x--;
        }
        curr->value=n;
    }
    
    int fn(Trie* root,int key){
        Trie* curr=root;
        int x=31;
        while(x>=0){
            
            bool d = (key & (1 << x));
            //cout<<d<<" ";
            if(curr->children[d]!=NULL)  curr=curr->children[d];
            else if(curr->children[1-d]!=NULL)    curr=curr->children[1-d];
            
            x--;
        }
        return (key ^ curr->value);
    
    }
    
    int minxorpair(int n, int arr[]){    
        //code here
        int m=INT_MAX;
        
        Trie* root = new Trie;
        insert(root,arr[0]);

        for(int i=1; i<n; i++){
           // cout<<arr[i]<<" ";
            m = min(m, fn(root,arr[i]));
            insert(root,arr[i]);
        }
        
        return m;
    }
};
