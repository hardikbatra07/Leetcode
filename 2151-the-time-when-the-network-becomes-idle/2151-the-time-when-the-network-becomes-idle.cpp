class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        vector<vector<int>> adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(n,INT_MAX);
        set<pair<int,int>> s;
        s.insert({0,0});
        while(!s.empty()){
            int dis=s.begin()->first;
            int node=s.begin()->second;
            s.erase(s.begin());
            for(auto it:adj[node]){
               if(dist[it]==INT_MAX){
                dist[it]=1+dis;
                s.insert({dist[it],it});
               }
               else if(dist[it]>(1+dis)){
                s.erase({dist[it],it});
                dist[it]=1+dis;
                s.insert({dist[it],it});
               }
            }
        }
        int maxi=-1;
        for(int i=1;i<n;i++){
            int ans=2*dist[i];
            int y=((ans-1))/patience[i];
            int z=y*patience[i];
            int ans1=ans+z;
            maxi=max(maxi,ans1);
        }
return maxi+1;
    }
};