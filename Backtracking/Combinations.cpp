/*
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
You may return the answer in any order.

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

Solution:                                                                                                                                  */
    vector<vector<int>> v;
    vector<vector<int>> combine(int n, int k) {
        vector<int>c;
        
        back(1,c,k,n);
        return v;
    }
    void back(int x,vector<int>c,int k,int n){
            if(c.size()==k){
                v.push_back(c);
                return;
            }
            for(int i=x;i<=n;i++){
               c.push_back(i);
               back(i+1,c,k,n) ;
               c.pop_back();
            }
      
    }
