class Solution {
public:
    int numWays(int n, int m) {
        int p = 1000000007;
        m = min(m, n + 1);
        vector<int> f(m);
        f[0] = 1;
        for (int i = 0; i < n; i++)
        {
            vector<int> g(m);
            for (int i = 0; i < m; i++)
            {
                g[i] = f[i];
                if (i > 0)
                {
                    g[i] = (g[i] + f[i - 1]) % p;
                }
                if (i + 1 < m)
                {
                    g[i] = (g[i] + f[i + 1]) % p;
                }
            }
            f.swap(g);
        }
        return f[0];
    }
};