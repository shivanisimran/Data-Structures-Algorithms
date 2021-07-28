/*
There's an array A consisting of N non-zero integers A1..N. 
A subarray of A is called alternating if any two adjacent elements in it have different signs 
(i.e. one of them should be negative and the other should be positive).

For each x from 1 to N, compute the length of the longest alternating subarray that starts at x - 
that is, a subarray Ax..y for the maximum possible y ≥ x. The length of such a subarray is y-x+1.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^5
-10^9 ≤ Ai ≤ 10^9


Input:
3
4
1 2 3 4
4
1 -5 1 -5
6
-5 -1 -1 2 -2 -3

Output:
1 1 1 1
4 3 2 1
1 1 3 2 1 1


Solution:                                             */
void solve()
{
  int n;
  cin>>n;
  vector<long long>a;
  vector<long long>dp(n,1);
  for(int i=0;i<n;i++){
     ll x;
     cin>>x;
     a.push_back(x);
  }
  for(int i=n-2;i>=0;i--){
     if(a[i]*a[i+1]<0)
         dp[i]=max(dp[i+1]+1,dp[i]);
  }
  for(int i=0;i<n;i++){
     cout<<dp[i]<<" ";
  }
  cout<<endl;
}
