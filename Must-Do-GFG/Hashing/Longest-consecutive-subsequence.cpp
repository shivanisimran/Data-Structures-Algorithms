/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, 
the consecutive numbers can be in any order.

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.

Solution:                                                                                                                                   */
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      unordered_map<int,int> mp;
       int c=0,m=0,ma=0;
      for(int i=0;i<n;i++) {
          mp[arr[i]]++;
          if(arr[i]>ma)   ma=arr[i]; //ma is range upto which integers are present in arr.
      }
     
      for(int i=0;i<=ma;i++){
          if(mp[i]){
              c++;
              m=max(m,c);
          }
          else  c=0;
      }
      return m;
    }
