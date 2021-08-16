/*
You are required to complete the two methods push which take one argument an integer 'x' to be pushed into the queue 
and pop which returns a integer poped out from other queue(-1 if the queue is empty).

Solution:                                                                                                    */
void StackQueue :: push(int x)
{
    // Your Code
    s1.push(x);
}

//Function to pop an element from queue by using 2 stacks.
int StackQueue :: pop()
{
        // Your Code
    if(s2.empty() && s1.empty())
        return -1;
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    int x=s2.top();
    s2.pop();
    return x;
}
