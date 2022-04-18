/*
You are given an array A of size N. The array contains integers and is of even length. The elements of the array represent N coin of values V1, V2, ....Vn. 
You play against an opponent in an alternating way.
In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin.

You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Input:
N = 4
A[] = {5,3,7,10}
Output: 15
Explanation: The user collects maximum
value as 15(10 + 5)

Solution:                                                                                                                             */
    long long dp[1001][1001];  
    long long fun(int arr[],int i,int j){
        
        if(dp[i][j]!=-1)  return dp[i][j];
        
        if(i>j)  return 0;
        if(i==j)  return dp[i][j]=arr[i];
        if(i==j+1)  return dp[i][j]=max(arr[i],arr[j]);
         
        
        return dp[i][j]=max(arr[i]+min(fun(arr,i+2,j),fun(arr,i+1,j-1)),
                   arr[j]+min(fun(arr,i+1,j-1),fun(arr,i,j-2))); 
       
    }

    long long maximumAmount(int arr[], int n){
        // Your code here
        memset(dp,-1,sizeof dp);
        return fun(arr,0,n-1);
        
    }
