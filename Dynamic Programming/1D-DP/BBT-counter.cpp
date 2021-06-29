/*
Given a height h, count and return the maximum number of balanced binary trees possible with height h. 
A balanced binary tree is one in which for every node, the difference between heights of left and right subtree is not more than 1.

Input : h = 3
Output : 15

Input : h = 4
Output : 315

Solution:
Since the difference between the heights of left and right subtree is not more than one, possible heights of left and right part can be one of the following: 
(h-1), (h-2)
(h-2), (h-1)
(h-1), (h-1)

count(h) = count(h-1) * count(h-2) + count(h-2) * count(h-1) + count(h-1) * count(h-1)
         = 2 * count(h-1) * count(h-2) + count(h-1) * count(h-1)
         = count(h-1) * (2*count(h - 2) + count(h - 1))   */


   long long int countBT(int h) { 
        // code here
        long long int a[h+1];
        a[0]=1,a[1]=1;
        for(int i=2;i<=h;i++){
            a[i] = (a[i-1]*(2*a[i-2]+a[i-1]))%1000000007;
        }
        return a[h];
    }
         
                  
