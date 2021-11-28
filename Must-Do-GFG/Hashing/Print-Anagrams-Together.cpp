/*
Complete the function Anagrams() that takes a list of strings as input and returns a list of groups 
such that each group consists of all the strings that are anagrams.

Input:
N = 5
words[] = {act,god,cat,dog,tac}

Output: 
god dog
act cat tac
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.

Solution:                                                                                                                                                    */
   vector<vector<string> > Anagrams(vector<string>& st) {
        //code here
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<st.size();i++){
            string k=st[i];
            sort(k.begin(),k.end());
            mp[k].push_back(st[i]);
        }
        vector<vector<string> >ans;
        for(auto i: mp){
            vector<string> v;
            for(auto s: i.second) v.push_back(s);
            ans.push_back(v);
        }
        return ans;
    }
