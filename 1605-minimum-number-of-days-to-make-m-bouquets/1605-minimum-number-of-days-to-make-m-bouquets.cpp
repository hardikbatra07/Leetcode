class Solution {
    bool can_make_m_boquets(int mid,vector<int> & nums,int k,int m){
        int i=0;
        int boquets=0;
        while(i<nums.size()){
            if(nums[i]<=mid){
             int j=i;
             int c=0;
             while(j<nums.size() && nums[j]<=mid && c<k){
                j++;
                c++;
             }
             if(c==k) boquets++;
             i=j;
            }
            else i++;
        }
        return boquets>=m;
    }
public:
int minDays(vector<int> nums, int m, int k) {
   int low=*min_element(nums.begin(),nums.end());
   int high=*max_element(nums.begin(),nums.end());
   int ans=-1;
   while(low<=high){
    int mid=(low+high)/2;
    if(can_make_m_boquets(mid,nums,k,m)){
        ans=mid;
        high=mid-1;
    }
    else{
        low=mid+1;
    }
   }
   return ans;
  }
};