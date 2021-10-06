/*
Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. 
If frequencies of two elements are same, then smaller number comes first.
Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows. 
The first line of each test case contains a single integer N denoting the size of array. 
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.

Output:
For each testcase, in a new line, print each sorted array in a seperate line. For each array its numbers should be seperated by space.


Example:
Input:
2
5
5 5 4 6 4
5
9 9 9 2 5

Output:
4 4 5 5 6
9 9 9 2 5


Solution:                                                                                                                                  */
#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>a,pair<int,int>b){
    if(a.second!=b.second)  return(a.second > b.second);
    return (a.first<b.first);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    unordered_map<int,int> mp;
	    for(int i=0;i<n;i++)  {
	        cin>>a[i];
	        mp[a[i]]++;
	    }
	  vector<pair<int,int>> v(n);
	  for(int i=0;i<n;i++){
	      v.push_back({a[i],mp[a[i]]});
	  }
	  sort(v.begin(),v.end(),comp);
	   for(int i=0;i<n;i++) cout<<v[i].first<<" ";
	   cout<<"\n";
	}
	return 0;
}
