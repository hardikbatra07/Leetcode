class Solution {
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,set<int> &s){
        if(s.find(node)!=s.end()) return;
        else{
            vis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it]) dfs(it,adj,vis,s);
            }
        }
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
     vector<vector<int>> adj(n);
     for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
     }
     set<int> s;
     for(auto it:restricted) s.insert(it);
     vector<int> vis(n,0);
     dfs(0,adj,vis,s);
     int c=0;
     for(int i=0;i<n;i++){
        if(vis[i]==1) c++;
      }
      return c;
    }
};