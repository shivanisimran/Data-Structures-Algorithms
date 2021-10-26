/*
Imagine you have a special keyboard with the following keys: 

Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

Find maximum numbers of A's that can be produced by pressing keys on the special keyboard N times.

Input: N = 7
Output: 9
Explaination: The best key sequence is 
key 1, key 1, key 1, key 2, key 3,
key4, key 4.

Solution:                                                                                                                     
1. Recursive:                                                                                                                                                 */
   long long int optimalKeys(int n){
        // code here
        if(n<=6) return n;
        long long int x=0;
        for(int i=3;i<n;i++){
           x=max(x, (i-1)*optimalKeys(n-i));
           //if(curr>x)   x=curr;
        }
        return x;
    }


//2.Memoized:
    long long int dp[76]={0};
    long long int optimalKeys(int n){
       if(n<=6)  return n;
     
       if(dp[n]!=0)   return dp[n];
       else{
           for(int i=3;i<n;i++){
              dp[n]=max(dp[n], (i-1)*optimalKeys(n-i));
           }
            return dp[n];
       }
        
    }
