class Solution {
public:
    int maxProduct(vector<int>& a) {
        vector<int> f(a.size());
        vector<int> g(a.size());
        f[0] = g[0] = a[0];
        int z = a[0];
        for (int i = 1; i < a.size(); i++)
        {
            f[i] = max(max(f[i - 1] * a[i], g[i - 1] * a[i]), a[i]);
            g[i] = min(min(f[i - 1] * a[i], g[i - 1] * a[i]), a[i]);
            z = max(z, max(f[i], g[i]));
        }
        return z;
    }
};