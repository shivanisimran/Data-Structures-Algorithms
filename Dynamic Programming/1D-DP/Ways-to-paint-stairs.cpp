/*Given n stairs and we have 2 colour yellow and green. 
  The task is that we have to paint given stairs by given colour
  with condition is that we cannot paints two yellow steps directly after each other.
  
Input : n = 1
Output : 2
A single stair can be colored either
as green or yellow.

Input : n = 3
Output : 5 */

//It follows Fibonacci Series.
  
#include <bits/stdc++.h>
using namespace std;
 
// Function to find the number of ways
int ways(int n)
{
    int W[n + 1];
 
    // take base case for 1 and 2
    W[1] = 2;
    W[2] = 3;
 
    for (int i = 3; i <= n; i++)
        W[i] = W[i - 1] + W[i - 2];
     
    return W[n];
}
 
// Driven code
int main()
{
    int n = 3;
    printf("%d", ways(n));
    return 0;
}
