/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed 

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.

Solution: We make temprory list of size k, by removing 1st node from head, and, adding to beginning of curr. Thus, curr is reversed list of size k.
CODE:                                                                                                  */
struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        node* prev=NULL;
        node* p=prev;
        
        while(head!=NULL){
            
            node* curr=new node(NULL);
             int c=k;
               while(c-- && head!=NULL){
           
               int x=head->data;
               head=head->next;
               node* z=new node(x);
               if(curr->data!=NULL)
                    z->next=curr;
               curr=z;
            }
            if(prev==NULL){
                 prev=curr;
                 p=prev;
            }
                
            else{
                while(p->next){
                    p=p->next;
                }
                 p->next=curr;
            }
                
        }
      
        return prev;
        
        
    }
