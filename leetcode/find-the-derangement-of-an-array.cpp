class Solution {
public:
    int findDerangement(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 2; i <= n; i++)
        {
            f[i] = (f[i - 1] + f[i - 2]) * (i - 1LL) % 1000000007;
        }
        return f[n];
    }
};