int f[103][33][33];
int fuckyou[33][33];
bool caonima(int j, int j2)
{
    if (j & j2)
    {
        return false;
    }
    int cao = 1, mark = 0;
    for (int l = 0; l < 5; l++)
    {
        if (j >> l & 1)
        {
            mark = 1;
        }
        else
        {
            if (j2 >> l & 1)
            {
                if (mark == 0)
                {
                    return false;
                }
            }
            else
            {
                mark = 0;
            }
        }
    }
    return true;
}
class Solution {
public:
    vector<int> a;
    int defendSpaceCity(vector<int>& t, vector<int>& p) {
        int n = 2;
        for (int i = 0; i < p.size(); i++)
        {
            n = max(n, p[i] + 2);
        }
        a.resize(n + 1);
        memset(f[0], 0x3f, sizeof f[0]);
        for (int i = 0; i < p.size(); i++)
        {
            a[p[i] + 1] |= 1 << (t[i] - 1);
        }
        f[0][0][0] = 0;
        int fuckcnt = 0;
        for (int j = 0; j < 32; j++)
        {
            for (int j2 = 0; j2 < 32; j2++)
            {
                fuckyou[j][j2] = caonima(j, j2);
                if (caonima(j, j2))
                {
                    fuckcnt ++;
                }
            }
        }
        // cout << fuckcnt << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                for (int j2 = 0; j2 < 32; j2++)
                {
                    f[i][j][j2] = 0x3f3f3f3f;
                    if (!fuckyou[j][j2])
                    {
                        continue;
                    }
                    for (int k = 0; k < 32; k++)
                    {
                        for (int k2 = 0; k2 < 32; k2++)
                        {
                            if (!fuckyou[k][k2])
                            {
                                continue;
                            }
                            int mask = j | j2;
                            int c = 0;
                            for (int l = 0; l < 5; l++)
                            {
                                if (j >> l & 1)
                                {
                                    c += 2;
                                }
                                else if (j2 >> l & 1)
                                {
                                    c += 1;
                                }
                                if (k >> l & 1)
                                {
                                    int x = 0;
                                    int y = 0;
                                    int u = 0;
                                    for (int m = l; m < 5; m++)
                                    {
                                        if ((k | k2) >> m & 1)
                                        {
                                            u |= 1 << m;
                                            if (mask >> m & 1)
                                            {
                                                x = 1;
                                            }
                                            if ((a[i] >> m & 1))
                                            {
                                                y = 1;
                                            }
                                        }
                                        else
                                        {
                                            break;
                                        }
                                    }
                                    if (!x && y)
                                    {
                                        c += 1;
                                        mask |= u;
                                    }
                                }
                            }
                            if ((mask & a[i]) == a[i])
                            {
                                f[i][j][j2] = min(f[i][j][j2], f[i - 1][k][k2] + c);
                            }
                        }
                    }
                }
            }
        }
        return f[n][0][0];
    }
};