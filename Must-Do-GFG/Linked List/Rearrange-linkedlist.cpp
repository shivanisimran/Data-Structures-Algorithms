/*
Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all even positions node are together.
Assume the first element to be at position 1 followed by second element at position 2 and so on.

Solution:                                                                                                          */
 void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       if(head==NULL || head->next==NULL || head->next->next==NULL)
             return;
       Node* o=head;
       Node* e=head->next;
       Node* p=e;
       int i=1;
      while(o->next->next && e->next->next){
        o->next=e->next;
        o=o->next;
        e->next=o->next;
        e=e->next;
      }
      if(o->next->next){
          o->next=e->next;
          o=o->next;
          e->next=NULL;
      }
      o->next=p;
      return;
    }
