/*
The task is to complete the function intersetPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) 
as input parameters and returns data value of a node where two linked lists intersect. 
If linked list do not merge at any point, then it should return -1.

Solution:                                                                                        */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node* h1=head1;
    Node* h2=head2;
    int l1=0,l2=0;
    while(h1){
        l1++;
        h1=h1->next;
    }
    
    while(h2){
        l2++;
        h2=h2->next;
    }
    h1=head1,h2=head2;
    //cout<<l1<<" "<<l2;
    if(l1>l2){
        int d=l1-l2;
        while(d>0){
            h1=h1->next;
            d--;
        }
    }
    else{
       int d=l2-l1;
        while(d>0){
            h2=h2->next;
            d--;
        } 
    }
    //cout<<h1->data<<" "<<h2->data;
    while(h1!=NULL && h2!=NULL){
        if(h1==h2){
            return h1->data;
        }
        h1=h1->next;
        h2=h2->next;
    }
    return -1;
}
