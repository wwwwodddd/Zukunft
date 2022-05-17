class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int i = 0; i < g.size(); i++)
        {
            a[g[i][0]][g[i][1]] = 1;
        }
        for (int i = 0; i < w.size(); i++)
        {
            a[w[i][0]][w[i][1]] = 2;
        }
        for (int i = 0; i < n; i++)
        {
            int b = 0;
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1)
                {
                    b = 3;
                }
                else if (a[i][j] == 2)
                {
                    b = 0;
                }
                else
                {
                    a[i][j] |= b;
                }
            }
            b = 0;
            for (int j = m - 1; j >= 0; j--)
            {
                if (a[i][j] == 1)
                {
                    b = 3;
                }
                else if (a[i][j] == 2)
                {
                    b = 0;
                }
                else
                {
                    a[i][j] |= b;
                }
            }
        }
        for (int j = 0; j < m; j++)
        {
            int b = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i][j] == 1)
                {
                    b = 3;
                }
                else if (a[i][j] == 2)
                {
                    b = 0;
                }
                else
                {
                    a[i][j] |= b;
                }
            }
            b = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (a[i][j] == 1)
                {
                    b = 3;
                }
                else if (a[i][j] == 2)
                {
                    b = 0;
                }
                else
                {
                    a[i][j] |= b;
                }
            }
        }
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0)
                {
                    z++;
                }
            }
        }
        return z;
    }
};