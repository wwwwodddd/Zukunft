class Solution {
public:
    vector<int> f;
    vector<int> c;
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
            c[x] += c[y];
            f[y] = x;
        }
    }
    int largestComponentSize(vector<int>& a) {
        int m = 100001;
        f.resize(m);
        c.resize(m);
        for (int i: a)
        {
            c[i]++;
        }
        for (int i = 0; i < m; i++)
        {
            f[i] = i;
        }
        for (int i = 2; i < m; i++)
        {
            int x = 0;
            for (int j = i; j < m; j += i)
            {
                if (c[j])
                {
                    if (x == 0)
                    {
                        x = j;
                    }
                    else
                    {
                        U(j, x);
                    }
                }
            }
        }
        int z = 0;
        for (int i = 0; i < m; i++)
        {
            z = max(z, c[i]);
        }
        return z;
    }
};