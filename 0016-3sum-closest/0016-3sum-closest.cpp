class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mindiff=INT_MAX;
        int ans=-1;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int diff=abs(sum-target);
                if(diff<mindiff){
                    ans=sum;
                    mindiff=diff;
                }
                if(sum==target){return target;}
                else if(sum<target) j++;
                else k--;
            }
        }
        return ans;
    }
};