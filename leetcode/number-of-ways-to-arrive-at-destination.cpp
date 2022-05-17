class Solution {
public:
    int countPaths(int n, vector<vector<int>>& e) {
        const int p = 1000000007;
        vector<vector<pair<int, int> > > a(n);
        vector<long> d(n, 1e18);
        vector<long> f(n, 0);
        for (int i = 0; i < e.size(); i++)
        {
            a[e[i][0]].push_back(make_pair(e[i][1], e[i][2]));
            a[e[i][1]].push_back(make_pair(e[i][0], e[i][2]));
        }
        set<pair<long, int> > s;
        d[0] = 0;
        f[0] = 1;
        s.insert(make_pair(d[0], 0));
        while (s.size() > 0)
        {
            int u = s.begin()->second;
            s.erase(s.begin());
            for (pair<int, double> i: a[u])
            {
                if (d[i.first] > d[u] + i.second)
                {
                    s.erase(make_pair(d[i.first], i.first));
                    d[i.first] = d[u] + i.second;
                    f[i.first] = f[u];
                    s.insert(make_pair(d[i.first], i.first));
                }
                else if (d[i.first] == d[u] + i.second)
                {
                    f[i.first] = (f[i.first] + f[u]) % p;
                }
            }
        }
        return f[n - 1];
    }
};