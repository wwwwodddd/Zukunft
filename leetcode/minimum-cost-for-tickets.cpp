class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp;
        dp.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            dp[i] = 1e9;
            for (int j = i - 1; j >= 0; j--) {
                if (days[i - 1] - days[j] + 1 <= 1) {
                    dp[i] = min(dp[i], dp[j] + costs[0]);
                }
                if (days[i - 1] - days[j] + 1 <= 7) {
                    dp[i] = min(dp[i], dp[j] + costs[1]);
                }
                if (days[i - 1] - days[j] + 1 <= 30) {
                    dp[i] = min(dp[i], dp[j] + costs[2]);
                }
            }
        }
        return dp[n];
    }
};