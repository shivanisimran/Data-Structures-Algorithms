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


/*One variation of above problem is when we don't have to reverse the leftover nodes.i.e, leave the node as it is when the size of remaining list is less than K.
In that, case, we check the lenght of remaining list, weather it is >= k or not.

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Solution:                                                                                            */

int length(ListNode* head){
        int c=0;
        while(head!=NULL){
             c++;
            head=head->next;
        }
        return c;   
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* prev=NULL;
         ListNode* p=prev;
         while(head!=NULL){
            int c=k;
            ListNode* curr=new ListNode(-1);
            if(length(head)>=c){
                while(c--){
                    int x=head->val;
                    head=head->next;
                    ListNode* z= new ListNode(x);
                    if(curr->val>=0)
                        z->next=curr;
                    curr=z;
                }
            }
            else{
               curr=head;
                head=NULL;
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


/*One more variation of this problem is to swap nodes pairwise. It can be solved using similar method, just putting K=2.
Input:
N = 7
value[] = {1,2,3,4,5,6,7}
Output: 2 1 4 3 6 5 7
Explanation:The linked list after swapping
becomes: 1 2 3 4 5 6 7 -> 2 1 4 3 6 5 7.

Solution:                                                                                           */
struct Node* pairwise_swap(struct Node* head)
{
    // your code here
    Node* prev =NULL;
    Node* p=prev;
    while(head!=NULL){
        Node* curr=new Node(-1);
        int c=2;
        while(c-- && head!=NULL){
            int x=head->data;
            head=head->next;
            Node* z=new Node(x);
            if(curr->data>=0){
                z->next=curr;
            }
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
