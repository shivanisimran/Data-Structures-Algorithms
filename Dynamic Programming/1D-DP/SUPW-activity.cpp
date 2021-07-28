/*
In ICO School, all students have to participate regularly in SUPW. 
There is a different SUPW activity each day, and each activity has its own duration. 
The SUPW schedule for the next term has been announced, including information about the number of minutes taken by each activity.

Nikhil has been designated SUPW coordinator. His task is to assign SUPW duties to students, including himself. 
The school's rules say that no student can go three days in a row without any SUPW duty.

Nikhil wants to find an assignment of SUPW duty for himself that minimizes the number of minutes he spends overall on SUPW.

Input:
10
3 2 1 1 2 3 1 3 2 1

Output:
4
(Explanation: 1+1+1+1)


Solution:
This problem is similar to Min Cost Climbing Stairs problem.
Let's see that problem first.

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
Input: cost = [10,15,20]
Output: 15
Explanation: Cheapest is: start on cost[1], pay that cost, and go to the top.
Code:                                     */
int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){  
            dp[i]=min(dp[i-1]+cost[i],dp[i-2]+cost[i]);
        }
        return min(dp[n-1],dp[n-2]);
    }

/* 
Now, going back to ouroriginal problem, it can be solved in a similar way:  

CODE:                                                                         */
void solve()
{
  int n;
  cin>>n;
  ll a[n];
  vector<ll>dp(n);
  for(int i=0;i<n;i++){
     cin>>a[i];
  }
  dp[0]=a[0];
  dp[1]=a[1];
  dp[2]=a[2];
 
 for(int i=3;i<n;i++){
     dp[i]=min({dp[i-1],dp[i-2],dp[i-3]})+a[i];    
 }
 cout<< min({dp[n-1],dp[n-2],dp[n-3]})<<endl;
}

