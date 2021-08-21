/*
Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'.
Input: N = 2, S = 9
Output: 90
Explaination: It is the biggest number 
with sum of digits equals to 9.

Solution:                                                                                                                             */
string findLargest(int n, int s){
        // code here
          if((s==0 && n>1) || s>9*n){
              return "-1";
          }
        string st="";
      
        for(int i=0;i<n;i++){
           
            int x=(min(s,9));
            st+=to_string(x);
            s-=x;
            
        }
        return st;
    }
