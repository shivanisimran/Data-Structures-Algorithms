/*
You are given two arrays, A and B, of equal size N. 
The task is to find the minimum value of A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1], where shuffling of elements of arrays A and B is allowed.

Input:
N = 3 
A[] = {3, 1, 1}
B[] = {6, 5, 4}
Output:
23 
Explanation:
1*6+1*5+3*4 = 6+5+12
= 23 is the minimum sum

Solution:                                                                                                */
long long int minValue(int a[], int b[], int n)
    {
        // Your code goes here
        sort(a,a+n);
        sort(b,b+n);
        reverse(a,a+n);
         long long int s=0;
        for(int i=0;i<n;i++){
            s+=a[i]*b[i];
        }
        return s;
    }
