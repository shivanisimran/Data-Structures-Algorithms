/*
Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. 
The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

The task is to complete the function segregate() which segregates the nodes in the linked list as asked in the problem statement 
and returns the head of the modified linked list.

Solution:                                                                                                                     */
Node* segregate(Node *head) {
        
        // Add code here
        Node* k=head;
        Node* m=head;
        int z=0,o=0,t=0;
        while(k){
            if(k->data==0){
                z++;
            }
            else if(k->data==1){
                o++;
            }
            else
                t++;
                
            k=k->next;        
        }
        while(z--){
            m->data=0;
            m=m->next;
        }
        while(o--){
            m->data=1;
            m=m->next;
        }
        while(t--){
            m->data=2;
            m=m->next;
        }
        return head;
    }
