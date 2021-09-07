/*
Given the array prices where prices[i] is the price of the ith item in a shop. 
There is a special discount for items in the shop, if you buy the ith item, then you will receive a discount equivalent to prices[j] where 
j is the minimum index such that j > i and prices[j] <= prices[i], otherwise, you will not receive any discount at all.

Return an array where the ith element is the final price you will pay for the ith item of the shop considering the special discount.

Example :
Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]

Solution: The problem can be seen as finding next element <= current element. If there is any such element in the array, then subtracting it fron the current element.                                                                                                     
CODE:                                                                                     */
vector<int> finalPrices(vector<int>& pr) {
         stack<int> st;
         vector<int> ans;
         for(int i=0;i<pr.size();i++)
              ans.push_back(pr[i]);
        
         for(int i=0;i<pr.size();i++){
             while(!st.empty() && pr[st.top()]>=pr[i]){
                ans[st.top()]-=pr[i];
                st.pop();
             }
             st.push(i);
         }
        return ans;
    }
