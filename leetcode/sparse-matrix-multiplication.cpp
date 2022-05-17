class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int l = b.size();
        int m = b[0].size();
        vector<vector<int> > c(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < l; k++)
            {
                if (a[i][k])
                {
                    for (int j = 0; j < m; j++)
                    {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
        }
        return c;
    }
};