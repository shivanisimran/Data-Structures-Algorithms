/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Solution:                                                                                                                                      */
    vector<vector<int>> v;
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        vector<int>c;
        for(int i=0;i<can.size();i++){
             back(i,can,c,t,0);
        }
       
        return v;
        
    }
    void back(int x,vector<int>&can,vector<int>c,int t,int s){
        int n=can.size();
        if(x>=0 && x<n){
            s+=can[x];
            c.push_back(can[x]);
            if(s==t){
                v.push_back(c);
                return;
            }
            if(s>t) return;
            
            for(int i=0;i<n;i++){
                back(x+i,can,c,t,s);
            }
        }
        else    return;
    }
