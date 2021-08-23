/*
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
complete the function mergeSort() which sort the linked list using merge sort function.

Solution:                                                                                                                   */

//function to merge two sorted linked list.
Node* merge(Node* a, Node* b)  {  
    Node* c=new Node(0);
    Node* k=c;
    while(a!=NULL && b!=NULL){
        if(a->data > b->data){
            c->next=b;
            c=c->next;
            b=b->next;
        }
        else{
            c->next=a;
            c=c->next;
            a=a->next;
        }
        
       }
       if(a){
          c->next=a;
       }
       if(b){
          c->next=b;
        }
       return k->next;
    }
  
//function to get mid node between two nodes a & b.
    Node* mid(Node* a, Node* b)  {
        Node* f=a;
        Node* s=a;
        while(f!=b && f->next!=b){
            f=f->next;
            s=s->next;
            
        }
        return s;
    }
 
//recursive function to perform merge sort.
    Node* f(Node* head, Node* tail){
        if(head==tail){
            Node* k=new Node(head->data);
            return k;
        }
        Node* m=mid(head,tail);
        Node* l=f(head,m);
        Node*r=f(m->next, tail);
        return merge(l,r);
    }

//function to find the last node
    Node* last(Node* head){
        while(head->next!=NULL){
            head=head->next;
        }
        return head;
    }
    Node* mergeSort(Node* head) {
        // your code here
        Node* z=last(head);
        return f(head,z);
    }
