/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Input: piles = [3,6,7,11], h = 8
Output: 4

Solution: 
This problem is similar to capacity to ship baggage problem.
We take l=0 and r=sum of all elements of given array as min and max value respectively.The ans would lie between these two, so, we perform binary search.
For each value, we check weather it is possible to finish with this speed or not.
If Yes, then we would store the result and furthur check for smaller values. If not, check for larger values.

CODE:                                                                                                        */
int minEatingSpeed(vector<int>& p, int h) {
        long long l=1,r=0,ans;
        for(int i=0;i<p.size();i++){
            r+=p[i];
        }
        while(l<=r){
            long long m=l+(r-l)/2;
            if(f(m,p,h)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
    
   //function to check weather it is possible to finish within 'h' hours with 'm' speed.
    bool f(long long m,vector<int>&p,int h){
        int c=0;
        for(int i=0;i<p.size();i++){
            c+=(p[i]+m-1)/m;
        }
        return (c<=h);
    }
