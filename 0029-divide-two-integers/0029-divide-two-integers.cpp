class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        int flag = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        long long di = abs((long long)dividend);
        long long div = abs((long long)divisor);

        long long ans = 0;
        while (di >= div) {
            int cnt = 0;
            while (di >= (div << (cnt + 1))) {
                cnt++;
            }
            ans += (1LL << cnt);
            di -= (div << cnt);
        }

        ans = flag * ans;
        if (ans > INT_MAX) return INT_MAX;
        return (int)ans;
    }
};
