class Solution {
public:
    bool hasValidPath(vector<vector<char>>& s) {
        vector<vector<vector<int> > > f;
        int n = s.size();
        int m = s[0].size();
        f.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            f[i].resize(m + 1);
            for (int j = 0; j <= m; j++)
            {
                f[i][j].resize(n + m);
            }
        }
        f[1][0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1][j - 1] == '(')
                {
                    for (int k = 1; k < n + m; k++)
                    {
                        f[i][j][k] |= f[i - 1][j][k - 1];
                        f[i][j][k] |= f[i][j - 1][k - 1];
                    }
                }
                else // ')'
                {
                    for (int k = 0; k + 1 < n + m; k++)
                    {
                        f[i][j][k] |= f[i - 1][j][k + 1];
                        f[i][j][k] |= f[i][j - 1][k + 1];
                    }
                }
            }
        }
        return f[n][m][0];
    }
};