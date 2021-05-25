Q: Write a program to reverse an array or string


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}

// } Driver Code Ends


//User function Template for C++

string reverseWord(string str){
    
  //Your code here
  int i=0,j=str.length()-1;
  while(i<j){
      swap(str[i],str[j]);
      i++;
      j--;
  }
  return str;
}
