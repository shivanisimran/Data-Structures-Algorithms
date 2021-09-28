/*
Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.

Your task is to find out the minimum number of roads required, and also determine which roads should be built.

Input

The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,…,n.

After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.

A road always connects two different cities, and there is at most one road between any two cities.

Output

First print an integer k: the number of required roads.

Then, print k lines that describe the new roads. You can print any valid solution.

Constraints
1≤n≤105
1≤m≤2⋅105
1≤a,b≤n
Example

Input:
4 2
1 2
3 4

Output:
1
2 3                                                                               

Solution:                                                                                                                                */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007
#define pb push_back
#define endl '\n' 
 
ll add(ll x, ll y){ll res=x+y; return res % mod;}
ll mul(ll x, ll y){ll res=x*y; return res%mod;}
ll p(ll x, ll y){ll res=1;x%=mod;while(y){if(y&1){res = mul(res,x);}y>>=1;x=mul(x,x);}return res;}
void precision(int n){cout<<fixed<<setprecision(n);}
//1<<X means 2^X
 
 
vector<int>adj[200000];
int vis[200000];
int m,n,z=0;
void dfs(int x){
    vis[x]=1;
    for(auto i: adj[x])  {
       if(!vis[i]) dfs(i);
    }
}
 
void solve(){
  
   cin>>n>>m;
  
   for(int i=0;i<n;i++){
      vis[i]=0;
   }
   for(int i=0;i<m;i++){
      int x,y;
      cin>>x>>y;
    
      adj[x].pb(y);
      adj[y].pb(x);
   }
   vector<pair<int,int>> v;
   for(int i=1;i<=n;i++){
      if(!vis[i]){
         z++;
         if(i!=1) (v.pb({i-1,i}));
         dfs(i);
      }
   }
   z--;
   cout<<z<<endl;
   for(int i=0;i<v.size();i++){
      cout<<v[i].first<<" "<<v[i].second<<endl;
   }
      
}
 
 
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
  
      solve();
   
  
   return 0;
}
