/*
Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
Input: n = 3
Output: 5

Solution:
Iterate through every node from 1 to n, taking it as root.
Then, count the number of left and right subtrees for each root, and store them in a dp array.
*/

   int numTrees(int n) {
        long long a[n+1];
        a[0]=1;
        a[1]=1;
        for(int i=2;i<=n;i++){
            a[i]=0;
            for(int j=1;j<=i;j++){
                a[i]+=a[j-1]*a[i-j];
            }
        }
        return a[n];
    }
