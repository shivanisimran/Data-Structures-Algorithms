/*
Complete the function knapSack() which takes maximum capacity W, weight array wt[], value array val[], 
and the number of items n as a parameter and returns the maximum possible value you can get.
You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3 */

//1.Recursive Solution:
  class Solution
   {
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       if(w==0||n==0)
            return 0;
       if(wt[n-1]<=w){
           return(max(val[n-1]+knapSack(w-wt[n-1],wt,val,n-1),knapSack(w,wt,val,n-1)));
       }  
       else{
           return(knapSack(w,wt,val,n-1));
       }
    }
};



//2.This method uses Memoization Technique (an extension of recursive approach).
class Solution
{
    public:
    int f(int w, int wt[], int val[], int n,int** dp){
       if(w==0||n==0)
            dp[n][w]= 0;
       if(dp[n][w]==-1) {
           if(wt[n-1]<=w){
             dp[n][w]=(max(val[n-1]+f(w-wt[n-1],wt,val,n-1,dp),f(w,wt,val,n-1,dp)));
           }  
           else{
              dp[n][w]=f(w,wt,val,n-1,dp);
           }
       }       
       return dp[n][w];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       int** dp;
       dp = new int*[n];
       for (int i = 0; i <= n; i++)
           dp[i] = new int[w + 1];
       for(int i=0;i<=n;i++){
          for(int j=0;j<=w;j++) {
              dp[i][j]=-1;
          }
       }
       return f(w,wt,val,n,dp);
       
    }
};


//3. Using Bottom-up(tabulation) approach:

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int>(w+1));
      
       for(int i=0;i<=n;i++){
           for(int j=0;j<=w;j++){
               if(i==0 || j==0)
                  dp[i][j]=0;
               else if(wt[i-1]<=j)
                   dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
               else
                    dp[i][j]=dp[i-1][j];
           }
       }
       return dp[n][w];
    }
};


