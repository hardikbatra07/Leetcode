class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n,INT_MAX),dist2(n,INT_MAX);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1) adj[i].push_back(edges[i]);
        }
        set<pair<int,int>> s;
        s.insert({0,node1});
        dist1[node1]=0;
        while(!s.empty()){
            int dis=s.begin()->first;
            int node=s.begin()->second;
            s.erase(s.begin());
            for(auto it:adj[node]){
                if(dist1[it]==INT_MAX){
                    dist1[it]=1+dis;
                    s.insert({dist1[it],it});
                }
                else if(dist1[it]>1+dis){
                    s.erase({dist1[it],it});
                    dist1[it]=1+dis;
                    s.insert({dist1[it],it});
                }
            }
        }
        s.insert({0,node2});
        dist2[node2]=0;
        while(!s.empty()){
            int dis=s.begin()->first;
            int node=s.begin()->second;
            s.erase(s.begin());
            for(auto it:adj[node]){
                if(dist2[it]==INT_MAX){
                    dist2[it]=1+dis;
                    s.insert({dist2[it],it});
                }
                else if(dist2[it]>1+dis){
                    s.erase({dist2[it],it});
                    dist2[it]=1+dis;
                    s.insert({dist2[it],it});
                }
            }
        }
        int ind=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
           if(dist1[i]!=INT_MAX && dist2[i]!=INT_MAX){
            if(mini>(max(dist1[i],dist2[i]))){
                mini=max(dist1[i],dist2[i]);
                ind=i;
            }
           }
        }
return ind;
    }
};