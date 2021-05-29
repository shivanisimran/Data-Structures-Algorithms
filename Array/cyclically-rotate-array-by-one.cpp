//Given an array, rotate the array by one position in clock-wise direction.
//Your task is to complete the function rotate() which takes the array A[] and its size N as inputs and modify the array.

void rotate(int a[], int n)
{
    int x=a[n-1];
    for(int i=n-1;i>0;i--){
        a[i]=a[i-1];
    }
    a[0]=x;
}
