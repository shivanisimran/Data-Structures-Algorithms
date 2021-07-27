/*
Your task is to Complete the function maxChainLen() 
which takes a structure p[] denoting the pairs and n as the number of pairs and returns the length of the longest chain formed.

Solution:
This problem is a variation of standard Longest Increasing Subsequence problem.
Following is a simple two step process. 
1) Sort given pairs in increasing order of first (or smaller) element. 
   Why do not need sorting? 
   Consider the example {{6, 8}, {3, 4}} to understand the need of sorting. 
   If we proceed to second step without sorting, we get output as 1. But the correct output is 2. 
   
2) Now run a modified LIS process where we compare the second element of already finalized LIS with the first element of new LIS being constructed. 

The structure to use is as follows
struct val{
	int first;
	int second;
};
*/

bool comp(val a,val b){ //To sort pairs in increasing order of their first element.
    return (a.first < b.first);
}
int maxChainLen(struct val p[],int n)
{
//Your code here
  int *dp = new int[sizeof( int ) * n ]; 
  int m=0;
  sort(p,p+n,comp);
  for (int i = 0; i < n; i++ ) 
        dp[i] = 1; 
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[j].second < p[i].first){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
     for (int i = 0; i < n; i++ ) 
        if ( m < dp[i] ) 
            m = dp[i]; 
            
   return m;  

}
