/*
You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. 
Suppose the stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the smallest possible weight of the left stone. If there are no stones left, return 0.

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation:
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.

Solution:                                                                                                                                 */
    int dp[31][3001];
    int knp(int s,vector<int>& st,int n){
        if(n==0 || s==0)    return 0;
        
        if(dp[n][s] != -1)  return dp[n][s];
        if(st[n-1]<=s) return dp[n][s] = max(st[n-1]+knp(s-st[n-1],st,n-1), knp(s,st,n-1));
        else return dp[n][s] = knp(s,st,n-1);
    }
    
    
    int lastStoneWeightII(vector<int>& stones) {
        int s=0,t;
        int n=stones.size();
        for(int i=0;i<n;i++)    s+=stones[i];
        t=s;
        s/=2;
        memset(dp,-1,sizeof(dp));
        return t-2*knp(s,stones,n);
    }
 
