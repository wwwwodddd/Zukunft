class Solution {
public:
    vector<long long> c;
    vector<long long> d;
    int n;
    void Rc(int x, int y)
    {
        for (x++; x <= n; x += x & -x)
        {
            c[x] += y;
        }
    }
    void Rd(int x, int y)
    {
        for (x++; x <= n; x += x & -x)
        {
            d[x] += y;
        }
    }
    long long Gc(int x)
    {
        long long re = 0;
        for (x++; x > 0; x -= x & -x)
        {
            re += c[x];
        }
        return re;
    }
    long long Gd(int x)
    {
        long long re = 0;
        for (x++; x > 0; x -= x & -x)
        {
            re += d[x];
        }
        return re;
    }
    long long goodTriplets(vector<int>& a, vector<int>& b) {
        n = a.size();
        vector<int> p(n);
        vector<int> r(n);
        vector<int> s(n);
        c.resize(n + 1);
        d.resize(n + 1);
        
        for (int i = 0; i < n; i++)
            r[a[i]] = i;
        for (int i = 0; i < n; i++)
            s[b[i]] = i;
        for (int i = 0; i < n; i++)
        {
            p[r[i]] = s[i];
        }
        long long z = 0;
        for (int i = 0; i < n; i++)
        {
            long long ci = Gc(p[i]);
            Rc(p[i],1);
            z += Gd(p[i]);
            Rd(p[i], ci);
        }
        return z;        
    }
};