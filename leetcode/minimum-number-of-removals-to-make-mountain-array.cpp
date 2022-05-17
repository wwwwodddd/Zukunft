class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size();
        vector<int> f(n), g(n), h(n);
        fill(f.begin(), f.end(), 0x3f3f3f3f);
        for (int i = 0; i < n; i++)
        {
            int p = lower_bound(f.begin(), f.end(), a[i]) - f.begin();
            g[i] = p;
            f[p] = a[i];
        }
        fill(f.begin(), f.end(), 0x3f3f3f3f);
        for (int i = n - 1; i >= 0; i--)
        {
            int p = lower_bound(f.begin(), f.end(), a[i]) - f.begin();
            h[i] = p;
            f[p] = a[i];
        }
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            if (g[i] && h[i])
            {
                z = max(z, g[i] + 1 + h[i]);
            }
        }
        return n - z;
    }
};