//Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
// The task is to complete the function maxSubarraySum() which takes arr and N as input parameters and returns the sum of subarray with maximum sum.

int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int m=0,s=0;
        for(int i=0;i<n;i++){
            s+=arr[i];
            m=max(s,m);
            if(s<0)
                s=0;
        }
        return max(m,s);
    }
