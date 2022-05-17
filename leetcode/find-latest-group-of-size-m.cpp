class Solution {
public:
    vector<int> f, c;
    int d, m;
    int F(int x)
    {
        return f[x] != x ? f[x] = F(f[x]) : x;
    }
    void U(int x, int y)
    {
        x = F(x);
        y = F(y);
        if (x != y)
        {
            if (c[x] == m)
            {
                d--;
            }
            if (c[y] == m)
            {
                d--;
            }
            f[x] = y;
            c[y] += c[x];
            if (c[y] == m)
            {
                d++;
            }
        }
    }
    int findLatestStep(vector<int>& a, int mm) {
        d = 0;
        m = mm;
        int n = a.size();
        f.resize(n + 2);
        c.resize(n + 2);
        for (int i = 1; i <= n; i++)
        {
            f[i] = i;
        }
        int z = -1;
        for (int i = 0; i < n; i++)
        {
            c[a[i]] = 1;
            if (c[a[i]] == m)
            {
                d++;
            }
            if (c[a[i] - 1])
            {
                U(a[i] - 1, a[i]);
            }
            if (c[a[i] + 1])
            {
                U(a[i] + 1, a[i]);
            }
            if (d)
            {
                z = i + 1;
            }
        }
        return z;
    }
};