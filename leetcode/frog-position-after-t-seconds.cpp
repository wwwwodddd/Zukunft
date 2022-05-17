class Solution {
public:
    vector<vector<int> > a;
    double z = 0;
    int _t;
    int _target;
    void dfs(int x, int y, int d, double p)
    {
        int c = a[x].size() - (x != 1);
        if (x == _target)
        {
            if (d == _t || d < _t && c == 0)
            {
                z = p;
            }
        }
        for (int i : a[x])
        {
            if (i != y)
            {
                dfs(i, x, d + 1, p / c);
            }
        }
    }
    double frogPosition(int n, vector<vector<int>>& e, int t, int target) {
        a.resize(n + 1);
        _t = t;
        _target = target;
        for (int i = 0; i < e.size(); i++)
        {
            a[e[i][0]].push_back(e[i][1]);
            a[e[i][1]].push_back(e[i][0]);
        }
        dfs(1, 0, 0, 1);
        return z;
    }
};