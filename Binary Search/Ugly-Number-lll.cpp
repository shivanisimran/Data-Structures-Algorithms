/*
An ugly number is a positive integer that is divisible by a, b, or c.
Given four integers n, a, b, and c, return the nth ugly number.

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.

Solution:  The concept used here is: 
           N(A u B u C) = N(A)+N(B)+N(C)-N(A n B)-N(B n C)-N(C n A)+N(A n B n C)  
           
           N(A) = No. of multiples of A.
           N(B) = No. of multiples of B.
           N(C) = No. of multiples of C.
           N(A u B u C) = No. of multiples of A,B or C i.e, ugly numbers.
           
           Then used binary search to find nth ugly number.
           
CODE:                                                                                                                                              */
    long long lcm(long long x,long long y){
        return (x*y)/__gcd(x,y);
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        int ans;
        long long l=0,r=2000000000,mid;
        
        while(l<=r){
            mid=l+(r-l)/2;
            int cnt=0;
            
            cnt+=mid/a; //N(a)
            cnt+=mid/b;  //N(b)
            cnt+=mid/c;  //N(c)
            
            cnt-=mid/lcm(a,b);  // N(a n b)
            cnt-=mid/lcm(c,b);   // N(c n b)
            cnt-=mid/lcm(a,c);  // N(a n c)
            
            cnt+=mid/lcm(a,lcm(b,c));  // N(a n b n c)
            
            if(cnt >= n){
                ans=mid;
                r=mid-1;
            }
            
            else    l=mid+1;
        }
        return ans;
    }        
