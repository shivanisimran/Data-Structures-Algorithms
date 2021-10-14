/*
Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.
Input:
N = 3
Output:
((()))
(()())
(())()
()(())
()()()

Solution:                                                                                                                                                 */
    vector<string> ans;
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> v;
        
        back(v,"",0,0,n);
        return ans;
    }

    void back(vector<string>& v,string str,int o,int c,int n){    
        if(str.size()==2*n){
            ans.push_back(str);
            return;
        }
        if(n>o){
            back(v,str+"(",o+1,c,n);
        }
        if(o>c){
           back(v,str+")",o,c+1,n);
        }
    }
