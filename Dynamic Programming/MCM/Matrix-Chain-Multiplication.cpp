/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. 
The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

Input: N = 5
arr = {40, 20, 30, 10, 30}
Output: 26000
Explaination: There are 4 matrices of dimension 
40x20, 20x30, 30x10, 10x30. Say the matrices are 
named as A, B, C, D. Out of all possible combinations,
the most efficient way is (A*(B*C))*D. 
The number of operations are -
20*30*10 + 40*20*10 + 40*10*30 = 26000.


Solution:                                                                                                                                             */
    int dp[101][101];
    int mcm(int arr[],int i,int j){
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
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof dp);
        return mcm(arr,1,N-1);
    }
