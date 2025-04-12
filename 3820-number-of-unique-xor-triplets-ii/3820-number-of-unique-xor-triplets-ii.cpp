class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<int> m(2048,0),m1(2048,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=nums[i]^nums[j];
                m[x]++;
            }
        }
        
      for (int x = 0; x < 2048; x++) {
    if (m[x] > 0) {
        for (int i = 0; i < n; i++) {
            int k = x ^ nums[i];
            m1[k]++;
        }
    }
}
        int c=0;
        for(auto it:m1){ if(it>=1) c++;}
        return c;
    }
};