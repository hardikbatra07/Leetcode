class Solution {
      int helper(vector<int> &a,int k,int n){
        if(k<0) return 0;
        int l=0,r=0;
        int c=0,ans=0;
        while(r<n){
            if(a[r]==1)c++;
            while(c>k){
                if(a[l]==1) c--;
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int n=a.size();
        vector<int> v;
        for(int i=0;i<n;i++){
            if(a[i]%2!=0) v.push_back(1);
            else v.push_back(0);
        }
        return helper(v,k,n)-helper(v,k-1,n);
    }
};