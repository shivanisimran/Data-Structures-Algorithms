//Move all negative numbers to beginning and positive to end with constant extra space

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,a[100000],k=0,j,m=0;
	cin>>n;
	j=n-1;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	while(k<j){
	    if(a[k]>0 && a[j]<0){
	        swap(a[k],a[j]);
	        k++;
	        j--;
	    }
	    else if(a[k]<0 && a[j]<0){
	        k++;
	    }
	    else if(a[k]>0 && a[j]>0){
	        j--;
	    }
	    else{
	        k++;
	        j--;
	    }
	}
	for(int i=0;i<n;i++){
	    cout<<a[i]<<" ";
	}
	return 0;
}
