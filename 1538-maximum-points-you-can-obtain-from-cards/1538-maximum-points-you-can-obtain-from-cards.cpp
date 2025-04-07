class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n=a.size();
        int i=k-1,j=n-1;
        int ans=0;
        for(int i=0;i<k;i++) ans+=a[i];
        int maxi=-1;
        while(k>0){
            maxi=max(maxi,ans);
            ans-=a[i];
            ans+=a[j];
            i--;
            j--;
            k--;
        }
        return max(maxi,ans);
    }
};