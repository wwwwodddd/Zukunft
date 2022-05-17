class Solution {
public:
    vector<int> f;
    int F(int x)
    {
        return f[x] != x ? f[x] = F(f[x]) : x;
    }
    int makeConnected(int n, vector<vector<int>>& a) {
        f.resize(n);
        for (int i = 0; i < n; i++)
        {
            f[i] = i;
        }
        int z = n - 1;
        for (int i = 0; i < a.size(); i++)
        {
            int x = F(a[i][0]);
            int y = F(a[i][1]);
            if (x != y)
            {
                f[x] = y;
                z--;
            }
        }
        if (a.size() < n - 1)
        {
            z = -1;
        }
        return z;
    }
};