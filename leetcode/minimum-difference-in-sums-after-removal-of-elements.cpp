class Solution {
public:
    long long minimumDifference(vector<int>& a) {
        int n = a.size() / 3;
        vector<long long> f(3 * n);
        vector<long long> g(3 * n);
        {
            long long s = 0;
            multiset<int> t;
            for (int i = 0; i < n; i++)
            {
                s += a[i];
                t.insert(a[i]);
            }
            f[n] = s;
            for (int i = n; i < 2 * n; i++)
            {
                s += a[i];
                t.insert(a[i]);
                s -= *--t.end();
                t.erase(--t.end());
                f[i + 1] = s;
            }
        }
        {
            long long s = 0;
            multiset<int> t;
            for (int i = 3 * n - 1; i >= 2 * n; i--)
            {
                s += a[i];
                t.insert(a[i]);
            }
            g[2 * n] = s;
            for (int i = 2 * n - 1; i >= n; i--)
            {
                s += a[i];
                t.insert(a[i]);
                s -= *t.begin();
                t.erase(t.begin());
                g[i] = s;
            }
        }
        long long z = 1e18;
        for (int i = n; i <= 2 * n; i++)
        {
            z = min(z, f[i] - g[i]);
        }
        return z;
    }
};