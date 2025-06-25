class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long x=0,ans=0;
        map<long long,int> m;
        m[0]=1;
        for(int i=0;i<n;i++){
            x^=nums[i];
            if(m.find(x)!=m.end()) ans+=m[x];
            m[x]++;
        }
        return ans;
    }
};