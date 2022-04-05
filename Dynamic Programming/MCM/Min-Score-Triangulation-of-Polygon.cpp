/*
You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the 
ith vertex (i.e., clockwise order).

You will triangulate the polygon into n - 2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, 
and the total score of the triangulation is the sum of these values over all n - 2 triangles in the triangulation.

Return the smallest possible total score that you can achieve with some triangulation of the polygon.

Input: values = [3,7,4,5]
Output: 144
Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
The minimum score is 144.


Solution:                                                                                                                                              */
    int dp[101][101];
    int mcm(vector<int>& arr,int i,int j){
        if(dp[i][j]!=-1)  return dp[i][j];
        if(i==j)    return dp[i][j]= 0;
        int m=INT_MAX;
        for(int k=i;k<j;k++){
            m=min(m, arr[i-1]*arr[k]*arr[j]
                     + mcm(arr,i,k)
                     + mcm(arr,k+1,j)
                 );
        }
        return dp[i][j]= m;
    }
    int minScoreTriangulation(vector<int>& v) {
        memset(dp,-1,sizeof dp);
        int n=v.size();
        return mcm(v,1,n-1);
    }
