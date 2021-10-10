/*
There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. 
You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

A person can see another person to their right in the queue if everybody in between is shorter than both of them. 
More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.

Input: heights = [10,6,8,5,11,9]
Output: [3,1,2,1,1,0]
Explanation:
Person 0 can see person 1, 2, and 4.
Person 1 can see person 2.
Person 2 can see person 3 and 4.
Person 3 can see person 4.
Person 4 can see person 5.
Person 5 can see no one since nobody is to the right of them.

Solution:We find the next greater element to the right as well as to the left for each person.
         A person[i] can view person[j] if:(1) person[j] is the next greater element to the right of person[i] or,
                                           (2) person[i] is the next greater element to the left of person[j].
CODE:                                                                                                                                                */
     vector<int> canSeePersonsCount(vector<int>& h) {
        stack<int>s1,s2;
        int n=h.size();
        vector<int> gl(n,-1);
        vector<int> gr(n,-1);
       
        for(int i=0;i<n;i++){
            while(!s1.empty() && h[i]>h[s1.top()]){
                gr[s1.top()]=i;
                s1.pop();
            }
            s1.push(i);
        }
       
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && h[i]>h[s2.top()]){
                gl[s2.top()]=i;
                s2.pop();
            }
            s2.push(i);
        }
       
        vector<int> ans(n,0);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[gl[i]]++;   
        }
        for(int i=0;i<n;i++){
            ans[i]+=mp[i];
            if(gr[i]!=-1)   ans[i]++;
        }
        return ans;
    }
