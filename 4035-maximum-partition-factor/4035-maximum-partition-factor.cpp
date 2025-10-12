class Solution {
    bool dfs(int u,int mid,vector<int> &a,vector<vector<int>> &dist,int col){
        a[u]=col;
        for(int j=0;j<dist.size();j++){
            if(u!=j){
                if(dist[u][j]<mid){
                    if(a[j]==-1){
                        if(!dfs(j,mid,a,dist,1-col)) return false;
                    }
                    else if(a[j]==col) return false;
                }
            }
        }
        return true;
    }
    int func(int mid,vector<vector<int>> &dist){
        int n=dist.size();
        vector<int> a(n,-1);
        for(int i=0;i<n;i++){
            if(a[i]==-1){
                if(!dfs(i,mid,a,dist,0)) return false;
            }
        }
        return true;
    }
public:
    int maxPartitionFactor(vector<vector<int>>& points) {
      int n=points.size();
      if(n==2) return 0;
      int maxi=-1;
      vector<vector<int>> dist(n,vector<int> (n,0));
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            dist[i][j]=dist[j][i]=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            maxi=max(maxi,dist[i][j]);
        }
      }
      int low=0,high=maxi;
      int ans=0;
      while(low<=high){
        int mid=(low+high)/2;
        if(func(mid,dist)){
            ans=mid;
            low=mid+1;       
        }
        else{
            high=mid-1;
        }
      }
      return ans;
    }
};