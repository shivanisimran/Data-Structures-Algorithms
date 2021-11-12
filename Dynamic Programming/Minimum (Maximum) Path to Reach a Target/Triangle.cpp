/*
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. 
More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Solution:                                                                                                                                     */
   int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
       
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                if(j<i && j>0) tri[i][j]+=min({tri[i-1][j],tri[i-1][j-1]});
                else if(j>0) tri[i][j]+=tri[i-1][j-1];
                else if(j<i) tri[i][j]+=tri[i-1][j];
            }
        }
        int m=INT_MAX;
        for(int i=0;i<tri[n-1].size();i++) m=min(m,tri[n-1][i]);
        return m;
   }
