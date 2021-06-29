/*There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top (order does matter).
  
Input: n = 10
Output: 89 
Explanation:  There are 89 ways to reach the 10th stair. */


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        long long a[1000001];
        a[1]=1; // we ca go to 1st stair in 1 way.
        a[2]=2; // we can go to 2nd stair in 2 ways, one from ground, other from the 1st stair.
        for(int i=3;i<=n;i++){
            a[i]=(a[i-1]+a[i-2])%1000000007; // at each level 'i' , we can reach either from (i-1)th stair or from (i-2)th stair.
        }
        return (a[n]);
    }
};
