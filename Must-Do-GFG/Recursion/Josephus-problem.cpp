/*
Given the total number of persons n and a number k which indicates that k-1 persons 
are skipped and kth person is killed in circle in a fixed direction.

The task is to choose the safe place in the circle so that when you perform these operations starting 
from 1st place in the circle, you are the last one remaining and survive.

Input:
n = 3 k = 2
Output: 3
Explanation: There are 3 persons so 
skipping 1 person i.e 1st person 2nd 
person will be killed. Thus the safe 
position is 3.

Solution:                                                                                                                */
    int solve(vector<int>&v,int k,int x){
        int n=v.size();
        if(v.size()==1) return v[0];
        v.erase(v.begin()+(x+k-1)%n);
        
        return solve(v,k,(x+k-1)%n);
    }
    
    int josephus(int n, int k)
    {
       //Your code here
        vector<int>v;
       
        for(int i=0;i<n;i++) v.push_back(i+1);
        return solve(v,k,0);
    }
