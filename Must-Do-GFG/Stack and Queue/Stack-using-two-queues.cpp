/*
Complete the two methods push() which takes an integer 'x' as input denoting the element to be pushed into the stack and 
pop() which returns the integer poped out from the stack(-1 if the stack is empty).

Solution:                                                                                                          */
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code 
        if(q1.empty())
             return -1;
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        
        int x=q1.front();
        q1.pop();
        queue<int> q=q1;
        q1=q2;
        q2=q;
        return x;
}
