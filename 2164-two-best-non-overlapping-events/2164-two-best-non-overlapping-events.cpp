class Solution {
int func(int ind,int cnt,vector<vector<int>> &dp,vector<int> &start,vector<vector<int>> &events,int n){
    if(cnt>=2) return 0;
    if(ind>=n) return 0;
    if(dp[ind][cnt]!=-1) return dp[ind][cnt];
    int take=0,not_take=0;
    not_take=func(ind+1,cnt,dp,start,events,n);
    int nextind=lower_bound(start.begin(),start.end(),events[ind][1]+1)-start.begin();
    take=events[ind][2]+func(nextind,cnt+1,dp,start,events,n);
    return dp[ind][cnt]=max(take,not_take);
    
}
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>> dp(n+1,vector<int> (3,-1));
        vector<int> start(n);
        for(int i=0;i<n;i++){
            start[i]=events[i][0];
        }
        return func(0,0,dp,start,events,n);
    }
};