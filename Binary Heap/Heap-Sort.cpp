/*
Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() which are used to implement Heap Sort.
Input:
N = 5
arr[] = {4,1,3,9,7}
Output:
1 3 4 7 9
Explanation:
After sorting elements
using heap sort, elements will be
in order as 1,3,4,7,9.

Solution:                                                                                                                                                         */
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
        int l,r,largest=i;
        if(2*i + 1 < n) {
            l=2*i + 1;
            if(arr[l]>arr[largest])  largest = l;
        }
        if(2*i + 2 < n) {
            r=2*i + 2;
            if(arr[r]>arr[largest])  largest = r;
        }
        
        if(i != largest){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i=n/2 - 1; i>=0; i--)  heapify(arr,n,i);
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        for(int i=n-1;i>0;i--){
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        } 
    }
