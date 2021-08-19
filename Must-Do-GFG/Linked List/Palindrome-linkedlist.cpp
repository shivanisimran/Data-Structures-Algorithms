/*
The task is to complete the function isPalindrome() which takes head as reference as the only parameter 
and returns true or false if linked list is palindrome or not respectively.

Solution(Recursive) :  We take two pointers l&r, initially both pointing to head. Using recursion, r reaches the last node, while l is still at head.
                       Then, we compare l & r values.
                       After which, we backtrack, r reaches its prev node, at the same time, we jump l to its next node, then compare l&r again..
                       
CODE:                                                                                                                               */
bool f(Node *r){
        if(r==NULL)
             return true;
                 
        bool k=f(r->next);
        if(k==false)  // if until now, any value is false, then return false.
            return false;
        if(r->data!=l->data){
            return false;
        }
        else{
           l=l->next; 
           return true;
        }
    }
    Node* l;
    bool isPalindrome(Node *head)
    {
        //Your code here
        l=head;
        return(f(head));
    }
