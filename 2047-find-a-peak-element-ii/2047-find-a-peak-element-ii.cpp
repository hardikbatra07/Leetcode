class Solution {
    int find_max_index(vector<vector<int>> &mat,int col){
        int maxi=-1;
        int ind=-1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]>maxi){
                maxi=mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int ind=find_max_index(mat,mid);
            int left=mid>0?mat[ind][mid-1]:-1;
            int right=mid<m-1?mat[ind][mid+1]:-1;
            if(mat[ind][mid]>left && mat[ind][mid]>right) return {ind,mid};
            else if(mat[ind][mid]<left) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
};