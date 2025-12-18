class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        vector<long long> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + 1LL * prices[i - 1] * strategy[i - 1];
        }

        long long maxi = pre[n];
        long long curr = 0;
        for (int i = k / 2; i < k; i++) {
            curr += prices[i];
        }
        for (int i = 1; i + k - 1 <= n; i++) {
            long long left = pre[i - 1];
            long long right = pre[n] - pre[i + k - 1];

            long long nxt = left + right + curr;
            maxi = max(maxi, nxt);
            if (i + k < n + 1) {
                curr += prices[i + k - 1];
                curr -= prices[i + k / 2 - 1];
            }
        }

        return maxi;
    }
};
