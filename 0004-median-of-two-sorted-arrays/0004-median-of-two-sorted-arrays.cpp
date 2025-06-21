class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
         int n1=arr1.size();
      int n2=arr2.size();
      if(n2<n1) return findMedianSortedArrays(arr2,arr1);
      int low=0,high=n1;
      int total_elements_on_left=(n1+n2+1)/2;
      while(low<=high){
         int mid=(low+high)/2;
         int from_first=mid;
         int from_second=total_elements_on_left-mid;
         int l1=INT_MIN,r1=INT_MIN;
         if(from_first>0){
            l1=arr1[from_first-1];
         }
         if(from_second>0){
            r1=arr2[from_second-1];
         }
         int l2=INT_MAX,r2=INT_MAX;
         if(from_first<n1){
            l2=arr1[from_first];
         }
         if(from_second<n2){
            r2=arr2[from_second];
         }
         if(l1<=r2 && r1<=l2){
            if((n1+n2)%2) return max(l1,r1);
            else return (max(l1,r1)+min(l2,r2))/2.0;
         }
         else if(l1>r2) high=mid-1;
         else low=mid+1; 
      }
      return -1;
    }
};