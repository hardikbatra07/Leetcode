class Solution {
public:
   int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        auto it=s.begin();
        int maxi=0;
        while(it!=s.end()){
             int j=*it;
             int start=j;
             while(it!=s.end() && j==*it){
                it++;
                j++;
             }
             maxi=max(maxi,j-start);
        }
        return maxi;
    }
};