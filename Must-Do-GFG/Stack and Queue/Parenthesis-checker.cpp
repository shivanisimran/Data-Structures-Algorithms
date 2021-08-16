/*
Complete the function ispar() that takes a string as a parameter and returns a boolean value true if brackets are balanced else returns false.

Solution:                                                                                                    */
bool ispar(string x)
    {
        // Your code here
        string a="{([";
        string b="})]";
        stack<char> st;
        for(int i=0;i<x.length();i++){
            if(st.empty())
                 st.push(x[i]);
            else if((st.top()==a[0] && x[i]==b[0]) || (st.top()==a[1] && x[i]==b[1]) || (st.top()==a[2] && x[i]==b[2])) 
                  st.pop();
            else
                 st.push(x[i]);
        }
        return(st.empty());
    }
