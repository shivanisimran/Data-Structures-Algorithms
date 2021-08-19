/*
 Complete the function removeLoop() which takes the head of the linked list as input parameter. 
 Simply remove the loop in the list (if present) without disconnecting any nodes from the list.
 
 Solution:                                                                                       */
void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node* slow=head;
        Node* fast=head;
        while(slow&& fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                while(fast->next!=slow)
                      fast=fast->next;
                fast->next=NULL;          
                
            }
        }
        
    }
 
