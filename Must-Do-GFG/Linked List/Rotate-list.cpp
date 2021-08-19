/*
Complete the function rotate() which takes a head reference as the first argument and k as the second argument, and returns the head of the rotated linked list.
N = 8
value[] = {1, 2, 3, 4, 5, 6, 7, 8}
k = 4
Output: 5 6 7 8 1 2 3 4

Solution:   We start from (k+1)th node till last, and add 1st k nodes next to it.                                                                                    
CODE:                                                                                                             */
Node* rotate(Node* head, int k)
    {
        // Your code here
        if(head->next==NULL)
             return head;
        Node* p=head;
        int c=0;
        while(p){
            c++;
            p=p->next;
        }
        k=k%c;
        Node* s=new Node(head->data);
        Node* t=s;
      
        while(k--){
            s->next=new Node(head->data);
            s=s->next;
            head=head->next;
        }
        
        Node* x=head;
        while(head->next!=NULL){
            head=head->next;
        }
        head->next=t->next;
        return x;
    }
