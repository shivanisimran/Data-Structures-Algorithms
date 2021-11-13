/*
There is only one character 'A' on the screen of a notepad. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

Input: n = 3
Output: 3
Explanation: Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.

Solution:                                                                                                                        */
   int minSteps(int n) {
        vector<int>dp(n+1,1000);
        if(n==1)    return 0;
        dp[0]=0;
        dp[1]=0;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(i%j==0){
                    int r=i/j;
                    dp[i]=min(dp[i], dp[r]+j);
                }
            }
        }
      
        return dp[n];
    }
