/*
Complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.
Input:
LinkedList: 2->7->8->9->10
Output: 10 9 8 7 2
Explanation: After reversing the list,
elements are 10->9->8->7->2.

Solution:      
1. Iterative: We make two pointers, prev & curr, curr pointing to head.
   then, make prev point to curr->next. And, jump prev& next one node forward.
   
   CoDE:                                                                                                                      */
   struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head==NULL || head->next==NULL)
             return head;
       // Node* temp=head;
        Node* prev=NULL;
        Node* curr=head;
        while(curr){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev; 
    } 

/*
2. Recursive:                                                                                     */
struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
        if(head==NULL || head->next==NULL)
             return head;
       Node* temp=reverseList(head->next); //this will take us to the last node, then, backtrack in reverse order.
       head->next->next=head;
       head->next=NULL;
        
       return temp;
    }
