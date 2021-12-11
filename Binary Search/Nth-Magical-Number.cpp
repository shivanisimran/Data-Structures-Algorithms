/*
A positive integer is magical if it is divisible by either a or b.
Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 109 + 7.

Input: n = 1, a = 2, b = 3
Output: 2

Solution:                                                                                                                            */
    long long lcm(long long x, long long y){
        return  (x*y)/__gcd(x,y);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        int mod=1e9+7;
        long long l=0, r=(long)n*min(a,b), mid, ans;
        
        while(l<=r){
            
            mid=l+(r-l)/2;
            int c=0;
            
            c += mid/a;
            c += mid/b;
            
            c -= mid/lcm(a,b);
            
            if(c >= n){
                ans=(mid)%mod;
                r=mid-1;
            }
            else  l=mid+1;  
        }
        return ans;
    }

 
