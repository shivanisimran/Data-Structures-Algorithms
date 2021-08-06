/*
Given an integer array bloomDay, an integer m and an integer k.

We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

Solution:
Possible no. of days lie between 1 to max element of given array.
So, we perforn binary search.

CODE:                                                    */
int minDays(vector<int>& b, int m, int k) {
        int l=1,r=*max_element(b.begin(),b.end()),ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(f(mid,m,k,b)){ // if it can be made in 'mid' days, we store result and check for even smaller no. of days.
                ans=mid;
                r=mid-1;
            }
            else   //else, we check for larger no. of days.
                l=mid+1;
        }
        return ans;
    }
    //function to check whether it is possible to make 'm' boquet in 'mid' days.
    bool f(int mid,int m,int k,vector<int>& b){
        if(m*k>b.size())
            return false;
        int c=0,ma=0;
        for(int i=0;i<b.size();i++){
            if(b[i]<=mid)
                  c++;
            else
                c=0; 
            if(c==k){
                ma++;
                c=0;
            }       
        }
        return(ma>=m);
            
    }
