//Given a string S, check if it is palindrome or not.
// Complete the function isPlaindrome() which accepts string S and returns a boolean value

/*Input: S = "abba"
Output: 1
Explanation: S is a palindrome */

class Solution{
public:	
	
	
	int isPlaindrome(string s)
	{
	    // Your code goes here
	    int n=s.length();
        int i=0,j=n-1;
        while(i<j){
           if(s[i]!=s[j])
               return 0;
        i++;
        j--;
        }
    return 1;
	}

};
