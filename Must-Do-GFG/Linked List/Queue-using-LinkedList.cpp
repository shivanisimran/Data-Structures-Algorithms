/*
Complete the function push() which takes an integer as input parameter and pop() which will remove and return an element(-1 if queue is empty).
Input:
Q = 5
Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation: n the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the
    queue will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.

Solution:                                                                                          */
void MyQueue:: push(int x)
{
        // Your Code
        QueueNode* a=new QueueNode(x);
        if(front==NULL){
            front=a;
            rear=a;
            return;
        }
        rear->next=a;
        rear=a;
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code 
        if(front==NULL){
            return -1;
        }
        if(front->next==NULL){
            int x=front->data;
            front=NULL;
            rear=NULL;
            return x;
        }
        else{
            int x=front->data;
            front = front->next;
            return x;
        }
}
