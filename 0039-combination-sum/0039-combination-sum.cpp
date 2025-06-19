class Solution {
    void func(int ind,vector<vector<int>> &ans,vector<int> temp,int sum,int target,vector<int> &a,int n){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target) return;
        if(ind==n) return;
        temp.push_back(a[ind]);
        func(ind,ans,temp,sum+a[ind],target,a,n);
        temp.pop_back();
        func(ind+1,ans,temp,sum,target,a,n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
           int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> v;
        func(0,ans,v,0,target,candidates,n);
        return ans;
    }

};