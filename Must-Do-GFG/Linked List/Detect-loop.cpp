/*
 Complete the function detectloop() which contains reference to the head as only argument. 
 This function should return true if linked list contains loop, else return false. 
 
 Solution:                                                                                                           */
bool detectLoop(Node* head)
    {
        // your code here
        Node* fast = head;
        Node* slow = head;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                   return true;
        }
        return false;
    }
