/*
Given N activities with their start and finish day given in array start[ ] and end[ ]. 
Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a given day.
Note : Duration of the activity includes both starting and ending day.

N = 4
start[] = {1, 3, 2, 5}
end[] = {2, 4, 3, 6}
Output: 
3
Explanation:
A person can perform activities 1, 2
and 4.

Solution: We can sort the activities according to their finishing time so that 
          we always consider the next activity as minimum finishing time activity.
          
          For sorting in increasing order of finishing time, we take priority queue and store finishing time,starting time aspair in it
          such that, activities are sorted acc to finishing time. 
          Then, we take next activity if its starting time is more than previous activity's finish time.
          
          
CODE:                                                                               */         
  int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({end[i],start[i]});
        }
        int c=1,x=pq.top().first;
        pq.pop();
        while(!pq.empty()){
            if(pq.top().second>x){
                c++;
                x=pq.top().first;
            }
            pq.pop();
        }
        return c;
    }
