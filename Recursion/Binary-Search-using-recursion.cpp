/*
Given a sorted array of size N and an integer K, find the position at which K is present in the array using binary search.
Input:
N = 5
arr[] = {1 2 3 4 5} 
K = 4
Output: 3
Explanation: 4 appears at index 3.

Solution:                                                                                                                                 */
class Solution{
public:
    int fn(int arr[], int l, int r, int k){
        if(l>r)  return -1;
        
        int mid=l+(r-l)/2;
        if(arr[mid]==k)  return mid;
        else if(arr[mid]<k)  return fn(arr,mid+1,r,k);
        else return fn(arr,l,mid-1,k);
    }
    int binarysearch(int arr[], int n, int k){
        // code here
        int l=0,r=n-1;
        return fn(arr,l,r,k);
        
    }
};
