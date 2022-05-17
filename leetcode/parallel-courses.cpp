class Solution {
public:
    vector<vector<int> > a;
    vector<int> f;
    vector<int> v;
    int z;
    int F(int x)
    {
        if (f[x])
        {
            return f[x];
        }
        if (v[x] == 1)
        {
            z = -1;
            return 0;
        }
        v[x] = 1;
        for (int i : a[x])
        {
            f[x] = max(f[x], F(i));
        }
        v[x] = 2;
        return ++f[x];
    }
    int minimumSemesters(int n, vector<vector<int>>& e) {
        a.resize(n);
        f.resize(n);
        v.resize(n);
        for (int i = 0; i < e.size(); i++)
        {
            a[e[i][0] - 1].push_back(e[i][1] - 1);
        }
        z = 0;
        for (int i = 0; i < n; i++)
        {
            int t = F(i);
            if (z != -1)
            {
                z = max(z, t);
            }
        }
        return z;
    }
};