class Solution {
int func(int ind,int last,vector<vector<int>> &dp,vector<string> &strs,int n,int m){
    if(ind<0) return 0;
    if(dp[ind][last]!=-1) return dp[ind][last];
    int take=0,not_take=0;
    not_take=func(ind-1,last,dp,strs,n,m);
    int flag=1;
    if(last!=m){
    for(int i=0;i<n;i++){
        if(strs[i][ind]>strs[i][last]){
            flag=0;
            break;
        }
    }
    }
    if(flag){
        take=1+func(ind-1,ind,dp,strs,n,m);
    }
    return dp[ind][last]=max(take,not_take);
}
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        vector<vector<int>> dp(m+1,vector<int> (m+1,-1));
        return m-func(m-1,m,dp,strs,n,m);
    }
};