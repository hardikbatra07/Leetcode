class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
            int n=a.size();
        int l=0,r=0;
        int maxi=0;
        int len=-1;
        int c=0;
        while(r<n){
          if(a[r]==1){
            len=r-l+1;
            maxi=max(maxi,len);
            r++;
          }
          else if(c<k){
            len=r-l+1;
            c++;
            maxi=max(maxi,len);
            r++;
          }
          else{
            while(c>=k){
                if(a[l]==0) c--;
                l++;
                len=r-l+1;
                maxi=max(maxi,len);
              
            }
          }
        }
        return maxi;
    }
};