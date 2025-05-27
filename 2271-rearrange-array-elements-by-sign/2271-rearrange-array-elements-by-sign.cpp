class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
            int n=nums.size();
        vector<int> ans(n);
        int j1=0,j2=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[j1]=nums[i];
                j1+=2;
            }
            else{
                ans[j2]=nums[i];
                j2+=2;
            }
        }
        return ans;
    }
};