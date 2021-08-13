/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)


Solution: We can sort the activities according to their finishing time so that 
          we always consider the next activity as minimum finishing time activity.
          
          For sorting in increasing order of finishing time, we take priority queue and store finishing time,starting time aspair in it
          such that, activities are sorted acc to finishing time. 
          Then, we take next activity if its starting time is more than previous activity's finish time.
          
          
CODE:                                                                          */         
  int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        for(int i=0;i<n;i++){
            pq.push({end[i],start[i]});
        }
        int c=1, x=pq.top().first;
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
