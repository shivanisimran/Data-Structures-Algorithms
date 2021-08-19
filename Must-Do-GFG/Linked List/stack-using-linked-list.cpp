/*
You are required to complete two methods push() and pop(). 
The push() method takes one argument, an integer 'x' to be pushed into the stack 
and pop() which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the pop() method.

Solution: We can do two things:
          1. Add new node to end of list, and remove from the end.
          2. Add new node to the beginning, and remove from beginning only.
          
          We will do 2nd method, because it will cost us O(1) , while removing from end would cost O(n).
          
CODE:                                                                                                            */
void MyStack ::push(int x) 
{
    // Your Code
    StackNode* a=new StackNode(x);
    if(top==NULL){
        top=a;
        return;
    }
    a->next=top;
    top=a;
    
}
//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(top==NULL)
        return -1;
    int x=top->data;
    top=top->next;
    return x;
}
