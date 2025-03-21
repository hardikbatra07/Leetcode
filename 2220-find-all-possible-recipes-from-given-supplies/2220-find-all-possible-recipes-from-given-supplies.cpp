class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string> s;
        int n=recipes.size();
        for(auto it:supplies) s.insert(it);
        vector<int> deg(n,0);
        map<string,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(auto it:ingredients[i]){
                if(s.find(it)==s.end()){
                    adj[it].push_back(i);
                    deg[i]++;
                }
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==0) q.push(i);
        }
        vector<string> ans;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string s=recipes[it];
            ans.push_back(s);
            for(auto it1:adj[s]){
               deg[it1]--;
               if(deg[it1]==0) q.push(it1);
            }
        }
        return ans;
    }
};