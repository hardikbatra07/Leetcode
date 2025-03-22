class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int,long long int> m;
    int n=edges.size();
    for(int i=0;i<n;i++){
        m[edges[i]]+=i;
    }
    long long int maxi=0,ans=0;
    for(auto it:m){
        if(maxi<it.second){
            maxi=it.second;
            ans=it.first;
        }
    }
    return ans;
    }
};