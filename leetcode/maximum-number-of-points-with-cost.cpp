class Solution {
public:
    long long maxPoints(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        vector<long long> f(m);
        long long z = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                f[j] += a[i][j];
                if (j > 0)
                {
                    f[j] = max(f[j], f[j - 1] - 1);
                }
                z = max(z, f[j]);
            }
            for (int j = m - 1; j > 0; j--)
            {
                f[j - 1] = max(f[j - 1], f[j] - 1);
            }
        }
        return z;
    }
};