class Solution {
public:
    void moveZeroes(vector<int>& nums) {
         int n=nums.size();
        int k=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                k=i;
                break;
            }
        }
        if(k!=-1){
          int i=0;
          while(i<n){
            if(nums[i]!=0 && i>k){
               swap(nums[i],nums[k]);
               k++;
            }
                   i++;
          }
        }
    }
};