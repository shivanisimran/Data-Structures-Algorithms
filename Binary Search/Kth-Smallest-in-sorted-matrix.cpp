/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
You must find a solution with complexity better than O(n2).

Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Solution:                                                                                                                                                  */
   int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        int l=mat[0][0],r=mat[n-1][m-1],ans;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(countless(mat,mid)>=k){
                ans=mid;
                r=mid-1;
            }
            else    l=mid+1;     
        }
        return ans;
    }
    
    int countless(vector<vector<int>>& mat,int x){
        int n=mat.size(),m=mat[0].size();
        int j=m-1,c=0;
        for(int i=0;i<n;i++){
            while(j>=0 && mat[i][j]>x) j--;
            c+=(j+1);
        }
        return c;
    }
