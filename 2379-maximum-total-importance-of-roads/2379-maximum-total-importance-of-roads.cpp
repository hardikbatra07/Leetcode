class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector< long long int> deg(n,0);
        for(auto it:roads){
            deg[it[0]]++;
            deg[it[1]]++;
        }
        sort(deg.rbegin(),deg.rend());
        long long int k=n;
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans+=k*deg[i];
            k--;
        }
        return ans;
    }
};