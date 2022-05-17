class Solution {
public:
    int n;
    vector<int> b;
    vector<int> f;
    vector<int> c;
    vector<pair<int, int> > d;
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
            f[x] = y;
            c[y] += c[x];
            n--;
        }
    }
    vector<int> groupStrings(vector<string>& a) {
        b.resize(a.size());
        f.resize(a.size());
        c.resize(a.size());
        n = a.size();
        for (int i = 0; i < a.size(); i++)
        {
            for (char c: a[i])
            {
                b[i] |= 1 << (c - 'a');
            }
            f[i] = i;
            c[i] = 1;
            d.push_back(make_pair(b[i], i));
            for (int j = 0; j < 26; j++)
            {
                if (b[i] >> j & 1)
                {
                    d.push_back(make_pair(b[i] ^ (1 << j), i));
                }
            }
        }
        sort(d.begin(), d.end());
        for (int i = 1; i < d.size(); i++)
        {
            if (d[i-1].first == d[i].first)
            {
                U(d[i-1].second, d[i].second);
            }
        }
        vector<int> z;
        z.push_back(n);
        int mx = 0;
        for (int i = 0; i < a.size(); i++)
        {
            mx = max(mx, c[F(i)]);
        }
        z.push_back(mx);
        return z;
    }
};