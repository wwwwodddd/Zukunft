class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& e) {
        vector<vector<int> > g(n + 1, vector<int>(n + 1, 0));
        vector<vector<int> > a(n + 1);
        vector<int> d(n + 1);
        for (int i = 0; i < e.size(); i++)
        {
            if (e[i][0] > e[i][1])
            {
                swap(e[i][0], e[i][1]);
            }
            d[e[i][0]]++;
            d[e[i][1]]++;
            a[e[i][0]].push_back(e[i][1]);
            g[e[i][0]][e[i][1]] = 1;
        }
        int z = 10 * n;
        for (int i = 1; i <= n; i++)
        {
            for (int j: a[i])
            {
                for (int k: a[j])
                {
                    if (g[i][k])
                    {
                        z = min(z, d[i] + d[j] + d[k] - 6);
                    }
                }
            }
        }
        if (z == 10 * n)
        {
            z = -1;
        }
        return z;
    }
};