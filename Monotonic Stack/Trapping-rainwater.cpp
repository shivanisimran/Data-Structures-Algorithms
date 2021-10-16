/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
              In this case, 6 units of rain water (blue section) are being trapped.
              
              
Solution: We keep a stack and iterate over the array. We add the index of the bar to the stack if bar is smaller than or equal to the bar 
at top of stack, which means that the current bar is bounded by the previous bar in the stack. 
If we found a bar longer than that at the top, we are sure that the bar at the top of the stack is bounded by the current bar and a previous bar in the stack, 
hence, we can pop it and add resulting trapped water to ans.

CODE:                                                                                                                                              */
   int trap(vector<int>& h) {
        stack<int>s1;
        int n=h.size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            while(!s1.empty() && h[i]>h[s1.top()]){
               int x=s1.top();
               s1.pop();
               if(s1.empty())   break;
               ans+=((min(h[i],h[s1.top()])-h[x])*(i-s1.top()-1));
            }
            s1.push(i);
        }
        
       
        return ans;
    }
