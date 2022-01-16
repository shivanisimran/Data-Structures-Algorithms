/*
Given a square chessboard, the initial position of Knight and position of a target. 
Find out the minimum steps a Knight will take to reach the target position.

Note: The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

N=6
knightPos[ ] = {4, 5}
targetPos[ ] = {1, 1}
Output:
3

Explanation:
Knight takes 3 step to reach from 
(4, 5) to (1, 1):
(4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

Solution:                                                                                                                                                   */
  int minStepToReachTarget(vector<int>&p,vector<int>&t,int n)
	{
	    // Code here
	    queue<pair<int,int>> q;
	    vector<vector<int>>vis(n+1);
	    for(int i=0;i<=n;i++) vis[i]=vector<int>(n+1,0);
	    
	    int a=t[0],b=t[1];
	    if(p[0]==a && p[1]==b)  return 0;
	    q.push({p[0],p[1]});
	    int c=0;
    
	    while(!q.empty()){
	        int z=q.size();
	        while(z--){
	            auto k=q.front();
	            q.pop();
	            int x=k.first,y=k.second;
	            if(x-1>=0 && y-2>=0 && !vis[x-1][y-2]){
	                q.push({x-1,y-2});
	                vis[x-1][y-2]=1;
	                if(x-1==a && y-2==b) return c+1;
	            }
	            if(x+1<=n && y-2>=0 && !vis[x+1][y-2]){
	                q.push({x+1,y-2});
	                vis[x+1][y-2]=1;
	                if(x+1==a && y-2==b) return c+1;
	            }
	            if(x-1>=0 && y+2<=n && !vis[x-1][y+2]){
	                q.push({x-1,y+2});
	                vis[x-1][y+2]=1;
	                if(x-1==a && y+2==b) return c+1;
	            }
	            if(x+1<=n && y+2<=n && !vis[x+1][y+2]){
	                q.push({x+1,y+2});
	                vis[x+1][y+2]=1;
	                if(x+1==a && y+2==b) return c+1;
	            }
	            if(x-2>=0 && y-1>=0 && !vis[x-2][y-1]){
	                q.push({x-2,y-1});
	                vis[x-2][y-1]=1;
	                if(x-2==a && y-1==b) return c+1;
	            }
	            if(x+2<=n && y-1>=0 && !vis[x+1][y-1]){
	                q.push({x+2,y-1});
	                vis[x+2][y-1]=1;
	                if(x+2==a && y-1==b) return c+1;
	            }
	            if(x-2>=0 && y+1<=n && !vis[x-2][y+1]){
	                q.push({x-2,y+1});
	                vis[x-2][y+1]=1;
	                if(x-2==a && y+1==b) return c+1;
	            }
	            if(x+2<=n && y+1<=n && !vis[x+2][y+1]){
	                q.push({x+2,y+1});
	                 vis[x+2][y+1]=1;
	                if(x+2==a && y+1==b) return c+1;
	            }
	        }
	        c++;
	    }
	    
	    return -1;
	}
