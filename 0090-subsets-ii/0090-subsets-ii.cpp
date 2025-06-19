class Solution {
    void func(int ind,vector<int> v,vector<vector<int>> &ans,int n,vector<int> &nums){
        if(ind==n){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        func(ind+1,v,ans,n,nums);
        v.pop_back();
        int next = ind + 1;
        while (next < n && nums[next] == nums[ind]) next++;
        func(next, v, ans, n, nums);  
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(),nums.end());
        func(0,v,ans,n,nums);
        return ans;
    }
};