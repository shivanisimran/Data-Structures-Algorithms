/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Solution:                                                                                                                                            */
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum3(int k, int t) {
        vector<int>c;
        back(1,k,c,t);
        return ans;
    }

     void back(int x,int k,vector<int>c,int t){
        if(t==0 && c.size()==k){
            ans.push_back(c);
            return;
        }
        if(t<0) return;
        for(int i=x;i<=9;i++){
            c.push_back(i);
            back(i+1,k,c,t-i);
            c.pop_back();
        }  
    }
