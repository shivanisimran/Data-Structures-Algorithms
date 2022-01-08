/*
Given an integer N, print all the N digit numbers in increasing order, such that their digits are in strictly increasing order(from left to right).

Input:
N = 2
Output:
12 13 14 15 16 17 18 19 23....79 89
Explanation:
For N = 2, the correct sequence is
12 13 14 15 16 17 18 19 23 and so on 
up to 89.

Solution:                                                                                                                                                 */
    vector<int> ans;
    vector<string> v1;
    
    void back(int x,int n,string s){
        if(s.length()==n){
            v1.push_back(s);
            return;
        }
        if(x>9) return;
        
        for(int i=x;i<=9;i++){
            s+=to_string(i);
            back(i+1,n,s);
            s.pop_back();
        }
    }

    vector<int> increasingNumbers(int N)
    {
        // Write Your Code here
        back(1,N,"");
        if(N==1) ans.push_back(0);
        for(string s: v1){
            ans.push_back(stoi(s));
        }
        return ans;
    }
