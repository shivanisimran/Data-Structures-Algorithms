/*
In IPL 2025, the amount that each player is paid varies from match to match. 
The match fee depends on the quality of opposition, the venue etc.

The match fees for each match in the new season have been announced in advance. 
Each team has to enforce a mandatory rotation policy so that no player ever plays three matches in a row during the season.

Nikhil is the captain and chooses the team for each match.
He wants to allocate a playing schedule for himself to maximize his earnings through match fees during the season.

Input:
5 
10 3 5 7 3 
Output:
23
(Explanation: 10+3+7+3) 

Solution:                                                                */
void solve()
{
  ll n,a[200000];
  cin>>n;
  for(int i=0;i<n;i++){
     cin>>a[i];
  }
  vector<ll>dp(n);
  dp[0]=a[0];
  dp[1]=a[0]+a[1];
  dp[2]=max({a[0]+a[1], a[1]+a[2], a[0]+a[2]});

  for(int i=3;i<n;i++){
     dp[i]=max({a[i]+dp[i-2], dp[i-1], dp[i-3]+a[i-1]+a[i]});
  }
  cout<<dp[n-1]<<endl;
}
