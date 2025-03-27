class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         int n=intervals.size();
        vector<pair<int,int>> p(n);
        for(int i=0;i<n;i++){
            p[i].first=intervals[i][1];
            p[i].second=intervals[i][0];
        }
        sort(p.begin(),p.end());
        int c=0;
        int last=p[0].first;
        for(int i=1;i<n;i++){
           if(p[i].second<last) c++;
           else last=p[i].first;
        }
        return c;
    }
};