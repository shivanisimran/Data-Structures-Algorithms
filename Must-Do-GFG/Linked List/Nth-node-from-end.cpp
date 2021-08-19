/*
Complete the function getNthFromLast() which takes two arguments: reference to head and N 
and you need to return Nth from the end or -1 in case node doesn't exist.

Solution:                                                                                     */
int getNthFromLast(Node *head, int n)
{
       // Your code here
       int c=0;
       Node* h=head;
       while(h){
           c++;
           h=h->next;
       }
       if(n>c)
           return -1;
       c=(c-n+1);
       h=head;
       while(c>1){
           h=h->next;
           c--;
       }
       return(h->data);
}
