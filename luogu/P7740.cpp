#include <bits/stdc++.h>
#define cerr cout
using namespace std;
const int Mod = 1e9 + 7;
int n, m, dp[2][2][71000], pw2[71000], pw3[71000];
char s[110];
vector<int> vec[1100], num[1100];
bool flag[4];
bitset<1005> bs[4][35];
bitset<1005> f[71000][4];
bitset<1005> all, v1, v2;
inline int add(int x, int y) {
    return x + y >= Mod ? x + y - Mod : x + y;
}
inline int dec(int x, int y) {
    return x - y < 0 ? x - y + Mod : x - y;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", s);
        int len = strlen(s);
        vec[i].push_back(2);
        // 2 unchanged
        // 3 xor by 1
        // 1 changed to 1
        // 0 changed to 0
        for (int j = 0; j < len; j++)
        {
            if (s[j] == 'R')
            {
                vec[i].push_back(2);
            }
            else if (s[j] == '*')
            {
                vec[i].back() ^= 1;
            }
            else
            {
                vec[i].back() = s[j] - '0';
            }
        }
        // vec[i].size() the changed length of the i-th tape
        num[vec[i].size()].push_back(i);
    }
    pw2[0] = 1; // power of 2
    pw3[0] = 1; // power of 3
    for (int i = 1; i <= n * m; i++)
    {
        pw2[i] = add(pw2[i - 1], pw2[i - 1]);
        pw3[i] = add(add(pw3[i - 1], pw3[i - 1]), pw3[i - 1]);
    }
    int ans = pw3[n * m]; // ???
    int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        all.set(i);
    }
    for (int r = n; r >= 0; r--)
    {
        for (int u : num[n - r + 1])
        {
            //钦定当前列-j为合法起点，那么当前列必须为0/1/2/3的是哪些行
            for (int j = 0; j < vec[u].size(); j++)
            {
                bs[vec[u][j]][j].set(u);
            }

            for (int j = vec[u].size(); j <= n + 2; j++)
            {
                bs[2][j].set(u);
            }

            tot++;
        }
        // tot rows chosen
        // choose all rows length <= n - r + 1
        // bs[operation][column_offset][row]

        dp[0][0][0] = 1;
        dp[0][1][0] = 0;
        // dp[0/1][0/1][s] 当前在第i列, <i-(n-r)的列有没有选，i-(n-r)..i列选的状态为s
        int limx;
        int limy;
        int now = 0, lst = 1;

        // first r rows
        for (int i = 1; i <= r; i++)
        {
            now ^= 1;
            lst ^= 1;
            limx = (1 << (min(n - r + 1, i - 1))) - 1;
            limy = (1 << (min(n - r + 1, i))) - 1;

            for (int y = 0; y < 2; y++)
            {
                for (int s = 0; s <= limy; s++)
                {
                    dp[now][y][s] = 0;
                }
            }

            for (int x = 0; x < 2; x++)
            {
                for (int s = 0; s <= limx; s++)
                {
                    int y = x | ((s << 1) > limy);
                    // s store last min(n - r + 1, i)) bitmask
                    // y store whether there is 1 before s
                    if (i != r) // if this row r, then we must choose this row
                    {
                        // do not choose row i, we can always fill empty
                        dp[now][y][(s << 1)&limy] = add(dp[now][y][(s << 1)&limy], dp[lst][x][s]);
                    }
                    // do choose row i, we can always fill empty
                    dp[now][y][(s << 1 | 1)&limy] = dec(dp[now][y][(s << 1 | 1)&limy], dp[lst][x][s]);
                    // choose a new row, change the sign
                }
            }

            for (int y = 0; y < 2; y++)
            {
                for (int j = 0; j < min(n - r + 1, i); j++)
                {
                    for (int t = 0; t < 4; t++)
                    {
                        // bs[operation][column_offset][row]
                        f[1 << j][t] = bs[t][j];
                        // f[column_subset][operator][row]
                    }
                }

                f[0][0] = 0;
                f[0][1] = 0;
                f[0][2] = ((y || i < r) ? all : 0);
                f[0][3] = 0;

                for (int s = 0; s <= limy; s++)
                {
                    for (int t = 0; t < 4; t++)
                    {
                        f[s][t] = f[s ^ (s & -s)][t] | f[s & -s][t];
                    }
                }
                for (int s = 0; s <= limy; s++)
                {
                    v1 = (f[s][0] & f[s][1]) | (f[s][2] & f[s][3]);
                    v2 = (f[s][0] | f[s][1]) & (f[s][2] | f[s][3]) & (all ^ v1);
                    dp[now][y][s] = 1ll * dp[now][y][s] * pw2[v2.count()] % Mod * pw3[tot - v1.count() - v2.count()] % Mod;
                }
            }
        }

        limy = (1 << (min(n - r + 1, r))) - 1;

        // last n - r rows
        for (int i = 1; i <= n - r; i++)
        {
            for (int y = 0; y <= 1; y++)
            {
                for (int j = 0; j < min(n - r + 1, r); j++)
                {
                    for (int t = 0; t < 4; t++)
                    {
                        f[1 << j][t] = bs[t][i + j];
                    }
                }

                f[0][0] = 0;
                f[0][1] = 0;
                f[0][2] = (y ? all : 0);
                f[0][3] = 0;

                for (int s = 0; s <= limy; s++)
                {
                    for (int t = 0; t < 4; t++)
                    {
                        f[s][t] = f[s ^ (s & -s)][t] | f[s & -s][t];
                    }
                }
                for (int s = 0; s <= limy; s++)
                {
                    v1 = (f[s][0] & f[s][1]) | (f[s][2] & f[s][3]);
                    v2 = (f[s][0] | f[s][1]) & (f[s][2] | f[s][3]) & (all ^ v1);
                    dp[now][y][s] = 1ll * dp[now][y][s] * pw2[v2.count()] % Mod * pw3[tot - v1.count() - v2.count()] % Mod;
                }
            }
        }

        for (int y = 0; y <= 1; y++)
        {
            for (int s = 0; s <= limy; s++)
            {
                ans = dec(ans, dp[now][y][s]);
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}