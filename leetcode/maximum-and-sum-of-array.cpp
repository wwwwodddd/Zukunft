class Solution {
public:
    int maximumANDSum(vector<int>& a, int m) {
        vector<int> b;
        for (int i = 1; i <= m; i++)
        {
            b.push_back(i);
            b.push_back(i);
        }
        vector<int> f(1 << b.size());
        int z = 0;
        for (int i = 0; i < 1 << b.size(); i++)
        {
            int c = __builtin_popcount(i);
            if (c >= a.size())
            {
                if (c == a.size())
                {
                    z = max(z, f[i]);
                }
                continue;
            }
            for (int j = 0; j < b.size(); j++)
            {
                if (~i >> j & 1)
                {
                    f[i | (1 << j)] = max(f[i | (1 << j)], f[i] + (a[c] & b[j]));
                }
            }
        }
        return z;
    }
};