class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int maxi=-1;
        while(l<r){
            maxi=max(maxi,(r-l)*min(height[l],height[r]));
            if(height[l]>height[r]) r--;
            else l++;
        }
        return maxi;
    }
};