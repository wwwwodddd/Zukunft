class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int> > l(n, vector<int>(m, 0));
        vector<vector<int> > r(n, vector<int>(m, 0));
        vector<vector<int> > u(n, vector<int>(m, 0));
        vector<vector<int> > d(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j > 0)
                {
                    l[i][j] = l[i][j - 1];
                }
                if (a[i][j] == 'W')
                {
                    l[i][j] = 0;
                }
                if (a[i][j] == 'E')
                {
                    l[i][j]++;
                }
            }
            for (int j = m - 1; j >= 0; j--)
            {
                if (j + 1 < m)
                {
                    r[i][j] = r[i][j + 1];
                }
                if (a[i][j] == 'W')
                {
                    r[i][j] = 0;
                }
                if (a[i][j] == 'E')
                {
                    r[i][j]++;
                }
            }
        }
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (i > 0)
                {
                    u[i][j] = u[i - 1][j];
                }
                if (a[i][j] == 'W')
                {
                    u[i][j] = 0;
                }
                if (a[i][j] == 'E')
                {
                    u[i][j]++;
                }
            }
            for (int i = n - 1; i >= 0; i--)
            {
                if (i + 1 < n)
                {
                    d[i][j] = d[i + 1][j];
                }
                if (a[i][j] == 'W')
                {
                    d[i][j] = 0;
                }
                if (a[i][j] == 'E')
                {
                    d[i][j]++;
                }
            }
        }
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '0')
                {
                    z = max(z, l[i][j] + r[i][j] + u[i][j] + d[i][j]);
                }
            }
        }
        return z;
    }
};