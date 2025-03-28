class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<int>& a, vector<int>& candy, vector<int>& vis) {
        if (vis[node] != -1) return;
        
        vis[node] = 0; 
        for (auto it : adj[node]) {
            if (vis[it] == -1) {
                dfs(it, adj, a, candy, vis);
            }
            
            if (a[node] > a[it]) {
                candy[node] = max(candy[node], candy[it] + 1);
            } else if (a[node] < a[it]) {
                candy[it] = max(candy[it], candy[node] + 1);
            }
        }
    }

public:
    int candy(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> adj(n); 
        for (int i = 0; i < n; ++i) {
            if (i > 0) adj[i].push_back(i - 1);  
            if (i < n - 1) adj[i].push_back(i + 1); 
        }
        
        vector<int> candy(n, 1);  
        vector<int> vis(n, -1);  
        for (int i = 0; i < n; ++i) {
            if (vis[i] == -1) { 
                dfs(i, adj, a, candy, vis);
            }
        }
        
        int totalCandies = 0;
        for (int i = 0; i < n; ++i) {
            totalCandies += candy[i];
        }
        
        return totalCandies;
    }
};
