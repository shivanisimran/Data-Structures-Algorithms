/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). 
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like 
(2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.


Solution:                      
The least possible(say l) capacity should be atleast the maxm of the individual weight present.
The maxm capacity(say r) needed in the worst case is equal to the sum of all the weights. It would be needed when d=1.
So, our required capacity would lie between l & r(both inclusive). Hence, we would perform binary search on capacity between l & r and check whether this capacity
is sufficient to deliver in D days.

CODE:                                                          */
int shipWithinDays(vector<int>& weights, int days) {
       int r=0,l=0,ans;
       for(int i=0;i<weights.size();i++){
           r+=weights[i];
           if(weights[i]>l)
               l=weights[i];
       }
        while(l<=r){
            int m=l+(r-l)/2;
            if(f(m,weights,days)){
                ans = m; //if this capacity is sufficient, we store it in ans,
                r=m-1;  //then, check if there is even smaller capacity possible, as we have to return the minimum capacity. 
            }
            else 
                l=m+1; // if this capicity is not sufficient, wewould check for larger values.
        }
       return ans;
    }
    
    //function to check whether it is possible to deliver using 'x' capacity within 'd' days.
    bool f(int x,vector<int> w,int d){
        int c=1,s=0;
        for(int i=0;i<w.size();i++){
            s+=w[i];
            if(s>x){               
                c++;
               s=w[i];  
            }   
        }
       return(c<=d);
    }
