/*
Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], 
the task is to list all words which are possible by pressing these numbers.

Input: N = 3, a[] = {2, 3, 4}
Output:
adg adh adi aeg aeh aei afg afh afi 
bdg bdh bdi beg beh bei bfg bfh bfi 
cdg cdh cdi ceg ceh cei cfg cfh cfi 
Explanation: When we press 2,3,4 then 
adg, adh, adi, ... cfi are the list of 
possible words.

Solution:                                                                                                                                           */
    vector<string> ans;
    unordered_map<int,string> mp;
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        
        back(a,n,0,"");
        return ans;
    }
    
    void back(int a[],int n,int x,string str){
        if(str.length()==n){
            ans.push_back(str);
            return;
        }
        for(int i=x;i<n;i++){
            for(auto j:mp[a[i]]){
                str+=j;
                back(a,n,i+1,str);
                str.pop_back();
           }
        }
    }
