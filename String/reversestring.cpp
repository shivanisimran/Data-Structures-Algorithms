//Write a function that reverses a string. The input string is given as an array of characters s.

/*Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"] */

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};
