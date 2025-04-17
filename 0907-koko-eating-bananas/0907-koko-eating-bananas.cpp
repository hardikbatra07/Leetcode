class Solution {
    int func(int mid,vector<int> &piles,int n,int h){
         int c=0;
         for(int i=0;i<n;i++){
            c+=(piles[i]+mid-1)/mid;
            if(c>h) return 0;
         }
         if(c<=h) return 1;
         else return 0; 
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=(low+high)/2;
            if(func(mid,piles,n,h)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};