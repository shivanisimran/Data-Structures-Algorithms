/*
Given a linked list and a value x, partition it such that all nodes less than x come first, 
then all nodes with value equal to x and finally nodes with value greater than or equal to x. 
The original relative order of the nodes in each of the three partitions should be preserved. The partition must work in-place.

Input:
1->4->3->2->5->2->3,
x = 3
Output:
1->2->2->3->3->4->5
Explanation: 
Nodes with value less than 3 come first, 
then equal to 3 and then greater than 3.

Solution:                                                                                          */
struct Node* partition(struct Node* head, int x) {
    // code here
    vector<int> v,w;
    int e=0;
    Node* h=head;
    while(h){
        if(h->data<x){
            v.push_back(h->data);
           
        }
        else if(h->data>x)
           w.push_back(h->data);
        else
            e++;
        
         h=h->next;        
    }
    Node* z=new Node(0);
    Node* q=z;
    int i=0;
    while(i<v.size()){
        z->next=new Node(v[i]);
        z=z->next;
        i++;
    }
    while(e--){
        z->next=new Node(x);
        z=z->next;
    }
    int j=0;
    while(j<w.size()){
        z->next=new Node(w[j]);
        z=z->next;
        j++;
    }
    
    return q->next;
}
