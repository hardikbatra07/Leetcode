class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        
        vector<bool> sorted(n, false);
        int ans = 0;
        for (int col = 0; col < m; col++) {
            bool flag = false;
            for (int i = 1; i < n; i++) {
                if (!sorted[i] && strs[i][col] < strs[i-1][col]) {
                    flag = true;
                    break;
                }
            }
            
            if (flag) {
                ans++;
                continue;
            }
            for (int i = 1; i < n; i++) {
                if (!sorted[i] && strs[i][col] > strs[i-1][col]) {
                    sorted[i] = true;
                }
            }
        }
        return ans;
    }
};
