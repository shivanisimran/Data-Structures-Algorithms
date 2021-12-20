/*
You are given an array of binary strings strs and two integers m and n.
Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
A set x is a subset of a set y if all elements of x are also elements of y.

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.

Solution: We can either select a string or leave it. So, it can be solved using similar concept of 0-1 knapsack.                                                   */

   //counting no. of '0's
    int z(string s){
        int c=0;
        for(char i: s){
            if(i=='0') c++;
        }
        return c;
    }
   
  //counting no. of '1's
    int o(string s){
        int c=0;
        for(char i: s){
            if(i=='1') c++;
        }
        return c;
    }
    
    int dp[101][101][601];
    int knp(vector<string>& strs,int m, int n, int x){
        if(x<0||(m<=0 && n<=0))    return 0;
        if(dp[m][n][x]!=-1)    return dp[m][n][x];
        
        if(z(strs[x])<=m && o(strs[x])<=n)
            return dp[m][n][x]=max(1+knp(strs, m-z(strs[x]),n-o(strs[x]),x-1), knp(strs, m, n, x-1));
        
        else return dp[m][n][x]= knp(strs, m, n, x-1);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        int x=strs.size()-1;
        return knp(strs,m,n,x);
    }
