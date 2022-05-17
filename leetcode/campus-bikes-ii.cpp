class Solution {
public:
    int assignBikes(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> f(1 << m, 1e9);
        f[0] = 0;
        int z = 1e9;
        for (int i = 0; i < 1 << m; i++)
        {
            int k = __builtin_popcount(i);
            if (k == n)
            {
                z = min(z, f[i]);
            }
            if (k >= n)
            {
                continue;
            }
            for (int j = 0; j < m; j++)
            {
                if (~i >> j & 1)
                {
                    int d = abs(a[k][0] - b[j][0]) + abs(a[k][1] - b[j][1]);
                    f[i | 1 << j] = min(f[i | 1 << j], f[i] + d);
                }
            }
        }
        return z;
    }
};