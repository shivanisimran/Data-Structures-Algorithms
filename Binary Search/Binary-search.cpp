/*
Complete the function binarysearch() which takes arr[], N and K as input parameters 
and returns the index of K in the array. If K is not present in the array, return -1.    */


int binarysearch(int arr[], int n, int k){
        // code here
        int l=0,r=n-1;
       
        while(l<=r){
             int m=(l+r)/2;
            if(arr[m]==k)
               return m;
            else if(arr[m]>k) {
               r=m-1;
            }
            else{
               l=m+1;
             }
        }
        return -1;
    }
