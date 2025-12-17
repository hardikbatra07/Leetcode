class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n=prices.size();
        long long  ans=0;
        k=min(k,n/2);
        vector<vector<long long>> dp1(k+1,vector<long long> (3,LLONG_MIN/2));
        dp1[0][0]=0;
        for(int i=0;i<=k;i++){
                dp1[i][1]=-prices[0];
            dp1[i][2]=prices[0];
        }
        for(int i=1;i<n;i++){
            vector<vector<long long>> dp2(k+1,vector<long long> (3,LLONG_MIN/2));
            for(int j=0;j<=k;j++){
                dp2[j][0]=max(dp2[j][0],dp1[j][0]);
                 dp2[j][1]=max(dp2[j][1],dp1[j][1]);
                 dp2[j][2]=max(dp2[j][2],dp1[j][2]);
                 dp2[j][2]=max(dp2[j][2],dp1[j][0]+prices[i]);
                dp2[j][1]=max(dp2[j][1],dp1[j][0]-prices[i]);

                if(j!=0){
                      dp2[j][0]=max({dp2[j][0],dp1[j-1][1]+prices[i],dp1[j-1][2]-prices[i]});
                }
                  
            }
            dp1=dp2;
        }
      for(int i=0;i<=k;i++) ans=max(ans,dp1[i][0]);
        return ans;
    }
};