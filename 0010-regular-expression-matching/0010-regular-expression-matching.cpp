class Solution {
    bool func(int i, int j, string &s, string &p, vector<vector<int>> &dp) {
        if (i < 0 && j < 0) return true;
        if (j < 0) return false;
        if (i < 0) {
            for (int k = 0; k <= j; k += 2) {
                if (k + 1 >= p.size() || p[k + 1] != '*') return false;
            }
            return true;
        }
        if (dp[i][j] != -1) return dp[i][j];

        if (p[j] == s[i] || p[j] == '.') {
            return dp[i][j] = func(i - 1, j - 1, s, p, dp);
        }
        else if (p[j] == '*') {
            if (j == 0) return dp[i][j] = false; 

            if (p[j - 1] == s[i] || p[j - 1] == '.') {
                return dp[i][j] = func(i - 1, j, s, p, dp) || func(i, j - 2, s, p, dp);
            }
            else {
                return dp[i][j] = func(i, j - 2, s, p, dp);
            }
        }
        else return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int x = s.size();
        int y = p.size();
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        return func(x - 1, y - 1, s, p, dp);
    }
};
