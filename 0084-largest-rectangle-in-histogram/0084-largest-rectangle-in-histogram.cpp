class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse(n),pse(n);
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.empty()){
               pse[i]=-1;
            }
            else pse[i]=s.top();
            s.push(i);
        }
         while(!s.empty()) s.pop();
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>heights[i]){
                s.pop();
            }
            if(s.empty()){
               nse[i]=n;
            }
            else nse[i]=s.top();
            s.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<pse[i]<<" "<<nse[i]<<endl;
            maxi=max(maxi,(heights[i]*(nse[i]-pse[i]-1)));
        }
        return maxi;
    }
};