class Solution {
public:
    int trap(vector<int>& a) {
       int n=a.size();
       int left=0;
       int right=n-1;
       int left_max_height=a[left];
       int right_max_height=a[right];
       int ans=0;
       while(left<right){
        if(left_max_height<right_max_height){
            left++;
            left_max_height=max(left_max_height,a[left]);
            ans=ans+(left_max_height-a[left]);
        }
        else{
            right--;
            right_max_height=max(right_max_height,a[right]);
            ans=ans+(right_max_height-a[right]);
        }
       }
       return ans;
    }
};