class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        int i=0;
        long long ans=0;
        while(i<n){
            int x=prices[i];
            int j=i+1;
            while(j<n && (x-prices[j])==1){
                x=prices[j];
                j++;
            }
            long long  k=(j-i);
            ans+=(k)*(k+1)/2;
            i=j;
        }
        return ans;
    }
};