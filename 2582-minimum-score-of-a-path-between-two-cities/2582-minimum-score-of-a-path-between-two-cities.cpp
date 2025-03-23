class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);
        map<int, vector<int>> m1;
        for(auto &path: roads){
            int u = path[0];
            int v = path[1];
            int wt = path[2];
            ds.unionBySize(u,v);
            int uu = ds.findUPar(u);
            int uv = ds.findUPar(v);
            m1[uu].push_back(wt);
            m1[uv].push_back(wt);
        }
        int head = ds.findUPar(1);
        int ans = INT_MAX;
        for(auto &pair: m1){
            if(ds.findUPar(pair.first) == head){
                for(int wt: pair.second){
                    ans = min(ans, wt);
                }
            }
        }
        return ans;
    }
};