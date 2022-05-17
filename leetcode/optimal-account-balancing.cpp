class Solution {
public:
    int minTransfers(vector<vector<int>>& t) {
        vector<int> a(12);
        for (auto e: t)
        {
            a[e[0]] -= e[2];
            a[e[1]] += e[2];
        }
        vector<int> f(1 << 12, 12);
        f[0] = 0;
        for (int i = 1; i < 1 << 12; i++)
        {
            int s = 0, c = 0;
            for (int j = 0; j < 12; j++)
            {
                if (i >> j & 1)
                {
                    s += a[j];
                    c++;
                }
            }
            if (s == 0)
            {
                f[i] = c - 1;
            }
        }
        for (int i = 0; i < 1 << 12; i++)
        {
            for (int j = i; j > 0; --j &= i)
            {
                f[i] = min(f[i], f[i ^ j] + f[j]);
            }
        }
        return f[(1 << 12) - 1];
    }
};