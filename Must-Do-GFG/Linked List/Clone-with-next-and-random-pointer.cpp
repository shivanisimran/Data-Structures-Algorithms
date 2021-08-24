/*
You are given a special linked list with N nodes where each node has a next pointer pointing to its next node. 
You are also given M random pointers, where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node has its value set to the value of its corresponding original node. 
Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. 
None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, 
where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Solution:                                                                                                            */
Node *copyList(Node *head)
    {
        //Write your code here
        Node* h=head;
        Node* temp=head;
        while(head){
            Node* z=new Node(head->data);
            z->next=head->next;
            head->next=z;
            
            head=z->next;
        }
       while(h!=NULL){
            Node* r=h->arb;
            if(r!=NULL){
                h->next->arb=r->next;
            }
            else{
                h->next->arb=NULL;
            }
            h=h->next->next;
        }
        
        Node* prev=new Node(-1);
        Node* p=prev;
        while(temp){
              prev->next=temp->next;
              temp->next=temp->next->next;
              prev=prev->next;
              temp=temp->next;
        }
        return p->next; 
     
        
    }
