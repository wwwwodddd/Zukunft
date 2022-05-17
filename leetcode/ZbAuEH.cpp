class Solution {
public:
    int getMaximumNumber(vector<vector<int>>& a) {
        a.push_back({0, -1, -1});
        sort(a.begin(), a.end());
        int f[3][3] = {};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                f[i][j] = -1e9;
            }
        }
        f[1][1] = 0;
        for (int k = 1; k < a.size(); k++)
        {
            int g[3][3] = {};
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    g[i][j] = -1e9;
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int i1 = 0; i1 < 3; i1++)
                    {
                        for (int j1 = 0; j1 < 3; j1++)
                        {
                            if (abs(i - i1) + abs(j - j1) <= a[k][0] - a[k - 1][0])
                            {
                                g[i][j] = max(g[i][j], f[i1][j1]);
                            }
                        }
                    }
                }
            }
            swap(f, g);
            f[a[k][1]][a[k][2]]++;
        }
        int z = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                z = max(z, f[i][j]);
            }
        }
        return z;
    }
};