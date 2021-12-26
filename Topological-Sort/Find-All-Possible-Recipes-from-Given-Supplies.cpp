/*
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. 
The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. 
Ingredients to a recipe may need to be created from other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.
Return a list of all the recipes that you can create. You may return the answer in any order.
Note that two recipes may contain each other in their ingredients.

Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
Output: ["bread"]
Explanation:
We can create "bread" since we have the ingredients "yeast" and "flour".

Solution:                                                                                                                                             */
     vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& sup) {
        vector<string> ans;
        unordered_map<string, vector<string>> adj;
        unordered_map<string,int> in;
        
        for(int i=0;i<rec.size();i++){
            for(auto c: ing[i]) {
                adj[c].push_back(rec[i]);
                in[rec[i]]++;
            }
        }
        
        queue<string>q;
        for(auto s:sup) q.push(s);
        
        while(!q.empty()){
            string k=q.front();
            q.pop();
            for(auto c: adj[k]) {
                in[c]--;
                if(in[c]==0) q.push(c);
            }
        }
        
        for(string r: rec) if(in[r]==0) ans.push_back(r);
        
        return ans;
        
        
    }
