class Solution {
      bool can_allocate(int mid,vector<int> &nums,int m){
        int sum=0;
        int cnt=1;
         for (auto i: nums) {
                if (sum + i <= mid) sum += i;
                else {
                    sum = i;
                    cnt ++;
                }
            }
            return cnt<=m;
    }
public:
    int splitArray(vector<int>& nums, int k) {
          int low=*max_element(nums.begin(),nums.end());
         int high=accumulate(nums.begin(),nums.end(),0);
         if (k > nums.size()) return -1;
         int ans=-1;
         while(low<=high){
            int mid=(low+high)/2;
            if(can_allocate(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
         }
         return ans;
    }
};