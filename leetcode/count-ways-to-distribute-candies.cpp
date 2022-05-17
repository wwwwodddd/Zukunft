class Solution {
public:
    int waysToDistribute(int n, int k) {
        vector<vector<long long> > f(n + 1, vector<long long>(k + 1, 0));
        f[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                f[i][j] = (f[i - 1][j] * j + f[i - 1][j - 1]) % 1000000007;
            }
        }
        return f[n][k];
    }
};