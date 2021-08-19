/*
Complete the function getMiddle() which takes a head reference as the only argument and should return the data at the middle node of the linked list.

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3.

Solution: This can be done using slow and fast pointers.                  
CODE:                                                                                                */
int getMiddle(Node *head)
{
   // Your code here
   Node *s=head;
   Node *f=head;
   while(f!=NULL && f->next!=NULL){
       s=s->next;
       f=f->next->next;
   }
   return s->data;
}
