class Solution {
    void dfs(int node, vector<vector<int>>& adj, set<int>& s) {
        s.insert(node);
        for (auto it : adj[node]) {
            if (s.find(it) == s.end()) dfs(it, adj, s);
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        
        for (int i = 0; i < n; i++) {
            int x = bombs[i][0], y = bombs[i][1], r = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    int x1 = bombs[j][0], y1 = bombs[j][1], r1 = bombs[j][2];
                    long long int distSquared = (long long int)(x1 - x) * (x1 - x) + (long long int)(y1 - y) * (y1 - y);
                    long long int rSquared = (long long int)r * r;  
                    if (distSquared <= rSquared) adj[i].push_back(j);
                }
            }
        }

        int maxi = 0;
        set<int> s;
        for (int i = 0; i < n; i++) {
            dfs(i, adj, s);
            maxi = max(maxi, (int)s.size());
            s.clear();
        }

        return maxi;
    }
};
