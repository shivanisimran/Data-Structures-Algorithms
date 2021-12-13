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

/* Merge of K soted lists can also be done in a similar way by calling same merge functions multiple times.

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Solution:                                                                                                                               */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* l3 = new ListNode();
        ListNode* t=l3;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                t->next=l1;
                l1=l1->next;
            }
            else{
                t->next=l2;
                l2=l2->next;
            }
            t=t->next;
        }
        if(l1){
            t->next=l1;
        }
        else if(l2){
            t->next=l2;
        }
        
        return l3->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>&lis) {
        if(lis.size()==0) return NULL;
        
         for(int i=1;i<lis.size();i++){
             lis[0]=mergeTwoLists(lis[0],lis[i]);
         }
        
        return lis[0];
    }
