/*
The problem is to count all the possible paths from top left to bottom right of a MxN matrix 
with the constraints that from each cell you can either move to right or down.

Input:
M = 3 and N = 3
Output: 6
Explanation:
Let the given input 3*3 matrix is filled 
as such:
A B C
D E F
G H I
The possible paths which exists to reach 
'I' from 'A' following above conditions 
are as follows:ABCFI, ABEHI, ADGHI, ADEFI, 
ADEHI, ABEFI

Solution:                                                                                     
1.Using Recursion:                                                                                                                                           */
long long numberOfPaths(int m,int n){
   if(m==1 || n==1)    return 1;
   return numberOfPaths(m-1,n)+numberOfPaths(m,n-1);
}



//2. Using Tabulation:
 long long numberOfPaths(int m,int n){
   int dp[m][n];
    dp[0][0]=1;
    for(int i=1;i<n;i++)    dp[0][i]=dp[0][i-1];
    for(int i=1;i<m;i++)    dp[i][0]=dp[i-1][0];
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
 }
    
