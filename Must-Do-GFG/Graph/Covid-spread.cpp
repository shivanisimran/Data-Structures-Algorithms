/*
Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected. 
If all patients are not infected after infinite units of time then simply return -1.

Input:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1 
Output:
2
Explanation:
Patients at positions {0,0}, {0, 3}, {1, 3}
and {2, 3} will infect patient at {0, 1}, 
{1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st 
unit time. And, during 2nd unit time, patient at 
{1, 0} will get infected and will infect patient 
at {2, 0}. Hence, total 2 unit of time is
required to infect all patients.


There is a similar problem called "rotting oranges".
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at 
indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
  

Solution: Both these problems would be solved by exactly same piece of code.
          We will do BFS traversal. 
          In one unit time, it will infect all its neighbours.                                               
CODE:                                                                                                                                                */
int helpaterp(vector<vector<int>> g)
    {
        //code here
        queue<pair<int,int>> q;
        int n=g.size(),m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==2){
                    q.push({i,j});
                    g[i][j]=0;
                } 
            }
        }
        int c=0;
        while(!q.empty()){
            int x=q.size();
            for(int k=0;k<x;k++){
                pair<int,int>p=q.front();
                int i=p.first,j=p.second;
                q.pop();
                if(i>0 && g[i-1][j]==1){
                     q.push({i-1,j});
                     g[i-1][j]=0;
                }
                if(i<n-1 && g[i+1][j]==1) {
                    g[i+1][j]=0;
                    q.push({i+1,j});
                }
                if(j>0 && g[i][j-1]==1) {
                    g[i][j-1]=0;
                    q.push({i,j-1});
                }
                if(j<m-1 && g[i][j+1]==1) {
                    g[i][j+1]=0;
                    q.push({i,j+1});
                }
            }
            c++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1){
                    return -1;
                } 
            }
        }
        return c-1;
    
    }

