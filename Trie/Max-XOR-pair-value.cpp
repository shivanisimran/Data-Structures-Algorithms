/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.

Solution:                                                                                                                            */

class Solution {
public:
    struct Trie{
        int value;
        Trie* children[2];
    };
    
    void insert(Trie* root ,int n){
        Trie* curr=root;
        
        int x=31;
        //int k=x^INT_MAX;
        while(x>=0){
            bool d = (n & (1 << x));
            
            if(!curr->children[d])   curr->children[d]=new Trie();
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
            
            if(curr->children[1-d]!=NULL)  curr=curr->children[1-d];
            else if(curr->children[d]!=NULL)    curr=curr->children[d];
            
            x--;
        }
        return (key ^ curr->value);
    
    }
    
    int findMaximumXOR(vector<int>& arr) {
        int m=INT_MIN, n=arr.size();
        if(n<2) return 0;
        Trie* root = new Trie();
        insert(root,arr[0]);

        for(int i=1; i<n; i++){
           // cout<<arr[i]<<" ";
            m = max(m, fn(root,arr[i]));
            insert(root,arr[i]);
        }
        
        return m;
    }
};
