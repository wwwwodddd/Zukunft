class Solution {
public:
    const int p = 1000000007;
    int f[51][51][101];
    int numOfArrays(int n, int l, int m) {
        for (int k = 1; k <= l; k++)
        {
            f[1][1][k] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int k = 1; k <= l; k++)
                {
                    f[i + 1][j][k] = (f[i + 1][j][k] + (long long)f[i][j][k] * k) % p;
                    for (int k2 = k + 1; k2 <= l; k2++)
                    {
                        f[i + 1][j + 1][k2] = (f[i + 1][j + 1][k2] + f[i][j][k]) % p;
                    }
                }
            }
        }
        int z = 0;
        for (int k = 1; k <= l; k++)
        {
            z = (z + f[n][m][k]) % p;
        }
        return z;
    }
};