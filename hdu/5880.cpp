#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <iostream>
using namespace std;
int n;
char s[1000020];
int t[1000020][26], tt;
int b[1000020];
int d[1000020];
int f[1000020];
int ins(char *s)
{
    int p = 0;
    for (; *s; s++)
    {
        if (t[p][*s - 'a'] == 0)
        {
            t[p][*s - 'a'] = ++tt;
        }
        p = t[p][*s - 'a'];
    }
    return p;
}

int idx(char c)
{
    if (islower(c))
    {
        return c - 'a';
    }
    if (isupper(c))
    {
        return c - 'A';
    }
    return 0;
}

void bd()
{
    int x, j;
    queue<int> q;
    q.push(0);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            if (t[u][i])
            {
                q.push(t[u][i]);
                f[t[u][i]] = (u == 0 ? 0 : t[f[u]][i]);
            }
            else
            {
                t[u][i] = (u == 0 ? 0 : t[f[u]][i]);
            }
            b[u] = max(b[u], b[f[u]]);
        }
    }
}

int main()
{
    int wocaonimawsmshiduozu;
    scanf("%d", &wocaonimawsmshiduozu);
    for (int caseseseseses = 0; caseseseseses < wocaonimawsmshiduozu; caseseseseses++)
    {
        for (int i = 0; i <= tt; i++)
        {
            memset(t[i], 0, sizeof t[i]);
            b[i] = 0;
            f[i] = 0;
        }
        tt = 0;
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++)
        {
            gets(s);
            b[ins(s)] = strlen(s);
        }
        bd();
        gets(s);
        int l = strlen(s);
        int p = 0;
        for (int i = 0; i < l; i++)
        {
            if (isalpha(s[i]))
            {
                p = t[p][idx(s[i])];
            }
            else
            {
                p = 0;
            }
            d[i] = b[p];
        }
        int del = 0;
        for (int i = l - 1; i >= 0; i--)
        {
            del = max(del, d[i]);
            if (del > 0)
            {
                s[i] = '*';
                del--;
            }
        }
        printf("%s\n", s);
    }
    return 0;
}