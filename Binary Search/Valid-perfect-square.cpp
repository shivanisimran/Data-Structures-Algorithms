/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt.


Solution:
We can do it using Binary search.                       */

bool isPerfectSquare(int n) {
        long long x;
        int i=1,j=n,m;
        while(i<=j){
            m=i+(j-i)/2;
             x=(long long)m*m;
            if(x==n)
                return true;
            if(x<n)
                i=m+1;
            else
                j=m-1;
        }
        return false;
    }
