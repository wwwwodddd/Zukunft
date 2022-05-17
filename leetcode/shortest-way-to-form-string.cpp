class Solution {
public:
    int shortestWay(string s, string t) {
        vector<vector<int> > f;
        int n = s.size();
        f.resize(n + 1);
        f[n].resize(26);
        fill(f[n].begin(), f[n].end(), n);
        for (int i = n - 1; i >= 0; i--)
        {
            f[i] = f[i + 1];
            f[i][s[i] - 'a'] = i;
        }
        int z = 0, p = n;
        for (int i = 0; i < t.size(); i++)
        {
            if (f[p][t[i] - 'a'] == n)
            {
                z++;
                p = 0;
            }
            p = f[p][t[i] - 'a'];
            if (p == n)
            {
                return -1;
            }
            p++;
        }
        return z;
    }
};