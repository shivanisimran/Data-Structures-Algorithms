//Sort an array of 0s, 1s and 2s
//Your task is to complete the function sort012() that takes an array arr and N as input parameters and sorts the array in-place.

void sort012(int a[], int n)
{
  int z=0,o=0,t=0;
  for(int j=0;j<n;j++){
      if(a[j]==0)
           z++;
      if(a[j]==1)
          o++;
      if(a[j]==2) 
           t++;
    }
    int i=0;
    while(z--){
        a[i++]=0;
       
    }
    while(o--){
        a[i++]=1;
        
    }
    while(t--){
        a[i++]=2;
        
    }
  
}
