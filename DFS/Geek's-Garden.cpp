/*
Geek has a rosarium and it has N*M slots, some of them are empty and some of them have roses. Given N*M character array consists of 0's and 1's. 
0 represents an empty spot and 1 represents a rose. The task is to find the maximum number of adjacent roses in geek's rosarium. 
For a spot (i, j) adjacent spots are (i+1, j), (i-1, j), (i, j-1), (i, j+1), (i-1, j-1), (i-1, j+1), (i+1, j-1),  and (i+1, j+1).

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains two space-separated integers N and M.
3. Next N lines consist of M characters.

Output: For each test case, print the maximum number of adjacent roses.

Constraints:
1. 1 <= T <= 100
2. 1 <= N, M <= 100
3. '0' <= arr[i][j] <= '1'

Example:
Input:
2
2 2
10
01
3 4
1001
0011
0101

Output:
2
5

Solution:                                                                                                                               */
#include <bits/stdc++.h>
using namespace std;

int g[100][100];
int vis[100][100];

void dfs(int n,int m,int i,int j,int& c){
    if(i>=0 && i<n && j>=0 && j<m && g[i][j]==1 && !vis[i][j]){
        c++;
        vis[i][j]=1;
        
        dfs(n,m,i+1,j,c);
        dfs(n,m,i-1,j,c);
        dfs(n,m,i,j+1,c);
        dfs(n,m,i,j-1,c);
        dfs(n,m,i+1,j-1,c);
        dfs(n,m,i+1,j+1,c);
        dfs(n,m,i-1,j-1,c);
        dfs(n,m,i-1,j+1,c);
    }
    else return;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    for(int i=0;i<n;i++){
	        string s;
	        cin>>s;
	        for(int j=0;j<m;j++){
	            g[i][j]=s[j]-'0';
	            vis[i][j]=0;
	        }
	    }
	    int z=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	           if(!vis[i][j]){
	               int c=0;
	               dfs(n,m,i,j,c);
	               z=max(z,c);
	           }
	        }
	    }
	    
	 	cout<<z<<"\n";  
	}

}
