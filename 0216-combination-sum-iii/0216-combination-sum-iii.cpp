class Solution {
 void func(int ind,int target,vector<vector<int>> &ans,vector<int> temp,vector<int> &nums,int size,int k){
        if(ind==size){
            if(target==0 && temp.size()==k){
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(nums[ind]);
        if(nums[ind]<=target) func(ind+1,target-nums[ind],ans,temp,nums,size,k);
        temp.pop_back();
        func(ind+1,target,ans,temp,nums,size,k);
    }
public:
    vector<vector<int> > combinationSum3(int k, int n) {
    	//your code goes here
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> ans;
        func(0,n,ans,temp,nums,9,k);
        return ans;
    }
};