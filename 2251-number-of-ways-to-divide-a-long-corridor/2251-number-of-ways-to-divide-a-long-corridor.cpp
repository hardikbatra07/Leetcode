class Solution {
    const int MOD=1e9+7;
    int func(int ind,int seats,string &a,vector<vector<int>> &dp,int n){
        if(ind == n) return seats == 2;
        if(dp[ind][seats]!=-1) return dp[ind][seats];
        if(a[ind]=='S') seats++;
        int first=0,second=0;
        if(seats==2){ 
            first=func(ind+1,0,a,dp,n);
            second=func(ind+1,2,a,dp,n);
        }
        else if(seats<2) second=func(ind+1,seats,a,dp,n);
        else return 0;
        return dp[ind][seats]=(first+second)%MOD;;
    }
public:
    int numberOfWays(string corridor) {
        int n =corridor.size();
        vector<vector<int>> dp(n+1,vector<int> (3,-1));
        return func(0,0,corridor,dp,n);
    }
};