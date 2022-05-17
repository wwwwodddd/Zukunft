class Solution {
public:
    vector<vector<int> > a;
    string s;
    int z = 0;
    int dfs(int x)
    {
        vector<int> b;
        b.push_back(0);
        b.push_back(0);
        for (int i: a[x])
        {
            int d = dfs(i);
            if (s[i] != s[x])
            {
                b.push_back(d);
            }
        }
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());
        z = max(z, 1 + b[0] + b[1]);
        return b[0] + 1;
    }
    int longestPath(vector<int>& p, string ss) {
        s = ss;
        int n = ss.size();
        a.resize(n);
        for (int i = 1; i < n; i++)
        {
            a[p[i]].push_back(i);
        }
        z = 0;
        dfs(0);
        return z;
    }
};