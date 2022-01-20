/*
You are given an integer n indicating there are n specialty retail stores. 
There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, 
where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). 

Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., 
you want to minimize the maximum number of products that are given to any store.

Return the minimum possible x.

Input: n = 6, quantities = [11,6]
Output: 3
Explanation: One optimal way is:
- The 11 products of type 0 are distributed to the first four stores in these amounts: 2, 3, 3, 3
- The 6 products of type 1 are distributed to the other two stores in these amounts: 3, 3
The maximum number of products given to any store is max(2, 3, 3, 3, 3, 3) = 3.

Solution:                                                                                                                                      */
   //returns number of shops which can get products if max is 'm'.
    int count(vector<int>& q,long long m){
        int c=0;
        for(int i: q) c+=(i+m-1)/m;
        return c;
    }

    int minimizedMaximum(int n, vector<int>& q) {
        long long s=0;
        int ans;
        for(int i:q) s+=i;
        long long l=1,r=s;
        while(l<=r){
            long long m=l+(r-l)/2;
            if(count(q,m)<=n) {
                ans=m;
                r=m-1;
            }
            else l=m+1;
           
        }
        
        return ans;
    }
