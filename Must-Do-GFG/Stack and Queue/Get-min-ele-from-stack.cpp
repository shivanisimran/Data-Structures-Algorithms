/*
Complete the three methods push() which take one argument an integer 'x' to be pushed into the stack, pop() 
which returns a integer poped out from the stack and getMin() which returns the min element from the stack. (-1 will be returned if for pop() and getMin() the stack is empty.)

Solution:                                                                */
int m;
void _stack::push(int x)
{
   //Your code here
       if(s.empty() ){
           s.push(x);
           m=x;
       }
       else if(x<m){
            s.push(x + x -m);
            m=x;
       }
       else{
           s.push(x);
       }
      

}
int _stack ::pop()
{
   //Your code here
   
   if(s.empty())
        return -1;
   int k=s.top();
   s.pop();
   if(k<m){
       int z=m;
       m = 2*m - k;
       return z;
   }
   else{
       return k;
   }
   
  
}

int _stack :: getMin()
{
   //Your code here
   if(s.empty())
        return -1;
   
   return m;
}
