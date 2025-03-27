class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& Intervals, vector<int>& newInterval) {
          vector<vector<int>> ans;
        int i = 0, n = Intervals.size();
        int l = newInterval[0], r = newInterval[1];
        while (i < n && Intervals[i][1] < l) {
            ans.push_back(Intervals[i]);
            i++;
        }
        while (i < n && Intervals[i][0] <= r) {
            l = min(l, Intervals[i][0]); 
            r = max(r, Intervals[i][1]);  
            i++;
        }
        ans.push_back({l, r});  
        while (i < n) {
            ans.push_back(Intervals[i]);
            i++;
        }

        return ans;
    }
};