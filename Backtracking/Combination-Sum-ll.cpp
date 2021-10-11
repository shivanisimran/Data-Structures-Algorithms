/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Solution:                                                                                                                                  */
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum2(vector<int>& can, int t) {
        vector<int>c;
        sort(can.begin(),can.end());
        back(0,can,c,t);
    
        return ans;
    }
    void back(int x,vector<int>&can,vector<int>c,int t){
        int n=can.size();
        if(t==0){
            ans.push_back(c);
            return;
        }
        if(t<0) return;
        for(int i=x;i<n;i++){
            if (i>x && can[i]==can[i-1])    continue;
            c.push_back(can[i]);
            back(i+1,can,c,t-can[i]);
            c.pop_back();
        }
        
    }
