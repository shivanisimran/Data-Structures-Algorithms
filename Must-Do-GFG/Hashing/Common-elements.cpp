/*
Given two lists V1 and V2 of sizes n and m respectively. Return the list of elements common to both the lists and return the list in sorted order. 
Duplicates may be there in the output list.

n = 5
v1[] = {3, 4, 2, 2, 4}
m = 4
v2[] = {3, 2, 2, 7}
Output:
2 2 3
Explanation:
The common elements in sorted order are {2 2 3}

Solution:                                                                                                                 */
    vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        unordered_map<int,int>mp;
        vector<int> v;
        for(int i=0;i<v1.size();i++)    mp[v1[i]]++;
        for(int j=0;j<v2.size();j++)    mp[v2[j]]--;
        
        for(int i=0;i<v1.size();i++){
            if(mp[v1[i]]<=0)  v.push_back(v1[i]);
            else    mp[v1[i]]--;
        }
        sort(v.begin(),v.end());
        return v;
    }
