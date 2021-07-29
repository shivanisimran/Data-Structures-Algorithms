/*
It's dinner time in Castle Camelot, and the fearsome Knights of the Round Table are clamouring for dessert. 
You, the chef, are in a soup. There are N knights, including King Arthur, each with a different preference for dessert, 
but you cannot afford to make desserts for all of them.
You are given the cost of manufacturing each Knight's preferred dessert–since it is a round table, 
the list starts with the cost of King Arthur's dessert, and goes counter-clockwise.

You decide to pick the cheapest desserts to make, such that for every pair of adjacent Knights, at least one gets his dessert. 
This will ensure that the Knights do not protest.

What is the minimum cost of tonight's dinner, given this condition?

For instance, suppose there are 5 Knights and their desserts cost 1, 2, 1, 2 and 2. 
In this case, the minimum cost is 4, which you can achieve by feeding the first, third and fourth (or fifth) Knights.

Solution:                                             */
void solve(){
  int n,ans,ans1;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++){
     cin>>a[i]; 
     
  }
   vector<ll>dp(n); //stores values in case the 1st element is sure to be chosen.
   vector<ll>dp1(n); //stores values in case the 1st element is not be chosen, hence, the last element must be chosen.
   dp[0]=a[0];  
   dp[1]=a[0]+a[1];
   for(int i=2;i<n;i++){
      dp[i]=min(dp[i-1]+a[i],a[i]+dp[i-2]); 
   }
   ans=min(dp[n-1],dp[n-2]); // if 1st element is chosen then, no barrier on last object,it may be chosen or may not be.
  
   dp1[0]=a[1];
   dp1[1]=a[1];
   for(int i=2;i<n;i++){
      dp1[i]=min(dp1[i-1]+a[i],a[i]+dp1[i-2]); 
   }
   ans1=dp1[n-1]; // 1st element was not chosen, so, last element must be chosen.
  cout<<min(ans,ans1)<<endl;
}

