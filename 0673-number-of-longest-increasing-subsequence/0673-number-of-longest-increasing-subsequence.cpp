class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
          int n=nums.size();
     vector<int> dp(n,1),hash(n,1);
     int maxi=1;
     for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
             if(nums[i]>nums[j]){
                if(dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=hash[j];
                }
                else if(dp[i]==(1+dp[j])){
                    hash[i]+=hash[j];
                }
             }
        }
        maxi=max(maxi,dp[i]);
     }
     int ans=0;
     for(int i=0;i<n;i++){
        if(dp[i]==maxi) ans+=hash[i];
     }
return ans;
    }
};