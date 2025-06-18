class Solution {
 int largestRectangleArea(vector<int> &heights) {
     int n=heights.size();
     int pse=-1,nse=n;
     int maxi=0;
     stack<int> s;
     for(int i=0;i<n;i++){
      while(!s.empty() && heights[s.top()]>heights[i]){
        auto num=s.top();
        s.pop();
        nse=i;
        pse=s.empty()?-1:s.top();
        maxi=max(maxi,heights[num]*(nse-pse-1));
      }
      s.push(i);
     }
       while (!s.empty()) {
            int num = s.top(); s.pop();
            int nse = n;
            int pse = s.empty() ? -1 : s.top();
            maxi = max(maxi, heights[num] * (nse - pse - 1));
        }

        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>> &matrix){
       int n=matrix.size();
       int m=matrix[0].size();
       vector<vector<int>> pre(n+1,vector<int> (m+1,0));
       for(int j=1;j<=m;j++){
          for(int i=1;i<=n;i++){
            if(matrix[i-1][j-1]=='0') pre[i][j]=0;
            else pre[i][j]=pre[i-1][j]+1;
          }
       }
       int maxi=0;
       for(int i=1;i<=n;i++){
        vector<int> temp;
        for(int j=1;j<=m;j++){
            temp.push_back(pre[i][j]);
        }
        maxi=max(maxi,largestRectangleArea(temp));
       }
       return maxi;
    }
};