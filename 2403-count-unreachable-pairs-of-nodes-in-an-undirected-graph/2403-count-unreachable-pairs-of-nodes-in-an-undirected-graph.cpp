class DisjointSet{
    vector<int> rank,parent,size;
public:
    DisjointSet(int n) {
     rank.resize(n+1,0);
     parent.resize(n+1);
     size.resize(n+1,1);
     for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findUpar(int node){
        if(node==parent[node]) return node;
        else return parent[node]=findUpar(parent[node]);
    }
    bool find(int u, int v) {
        return (findUpar(u)==findUpar(v));
    }

    void unionByRank(int u, int v) {
     int u1=findUpar(u);
     int v1=findUpar(v);
     if(u1==v1) return;
     if(rank[u1]<rank[v1]) parent[u1]=v1;
     else if(rank[v1]<rank[u1]) parent[v1]=u1;
     else{
        parent[u1]=v1;
        rank[v1]++;
     }
    }

    void unionBySize(int u, int v) {
        int u1=findUpar(u);
        int v1=findUpar(v);
        if(u1==v1) return;
        if(size[u1]<size[v1]){
            parent[u1]=v1;
            size[v1]+=size[u1];
        }
        else{
            parent[v1]=u1;
            size[u1]+=size[v1];
        }

    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {    
        DisjointSet ds(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            ds.unionBySize(u,v);
        }
        map<int,int> m;
        for(int i=0;i<n;i++){
            int n1=ds.findUpar(i);
            m[n1]++;
        }
        vector<long long int> v;
        for(auto it:m) v.push_back(it.second);
        int x=v.size();
        vector<long long int> pre(x+1,0);
        long long int ans=0;
        for(int i=1;i<=x;i++) pre[i]=pre[i-1]+v[i-1];
        for(int i=0;i<x;i++) ans+=v[i]*(pre[x]-pre[i+1]);
        for(auto it:m) cout<<it.first<<" "<<it.second<<endl;
return ans;
    }
};