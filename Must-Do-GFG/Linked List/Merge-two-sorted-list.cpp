/*
Given two sorted linked lists consisting of N and M nodes respectively. 
The task is to merge both of the list (in-place) and return head of the merged list.

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.

Solution:                                                                                            */
Node* sortedMerge(Node* h1, Node* h2)  
{  
    // code here
   if(h1==NULL) 
       return h2;
   if(h2==NULL)
        return h1;
   if(h1->data <= h2->data)
        h1->next=sortedMerge(h1->next, h2);
   else
        h2->next=sortedMerge(h2->next, h1);
}  
