/*
Given an array arr[ ] of length N consisting cost of N toys and an integer K depicting the amount with you. 
Your task is to find maximum number of toys you can buy with K amount. 

Input: 
N = 7 
K = 50
arr[] = {1, 12, 5, 111, 200, 1000, 10}
Output: 4
Explaination: The costs of the toys 
you can buy are 1, 12, 5 and 10.  

Solution:                                                                                                                   */
int toyCount(int n, int k, vector<int> arr)
    {
        // code here
        sort(arr.begin(),arr.end());
        int s=0,i=0;
        while(s+arr[i]<=k && i<n){
            s+=arr[i];
            i++;
        }
        return i;
    }
