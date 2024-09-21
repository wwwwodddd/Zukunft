#include <bits/stdc++.h>
using namespace std;
const int b = 20; // must > 1
int n, m, e;
int h[5003][203];
int v[5003][203];
int t[513][203][203];
int p[203][203];
void init(int x, int u, int d)
{
	for (int i = 1; i <= m; ++i)
	{
		for (int j = i, s = 0; j <= m; j++)
		{
			t[x][i][j] = s;
			s += h[u][j];
		}
		for (int j = i, s = 0; j > 0; --j)
		{
			t[x][i][j] = s;
			s += h[u][j - 1];
		}
		for (int j = 1; j <= m; ++j)
		{
			t[x][i][j] += v[u][j];
		}
		for (int k = u + 1; k <= d; k++)
		{
			for (int j = 1; j < m; j++)
			{
				t[x][i][j + 1] = min(t[x][i][j + 1], t[x][i][j] + h[k][j]);
			}
			for (int j = m - 1; j > 0; j--)
			{
				t[x][i][j] = min(t[x][i][j], t[x][i][j + 1] + h[k][j]);
			}
			for (int j = 1; j <= m; ++j)
			{
				t[x][i][j] += v[k][j];
			}
		}
	}
}
void merge(int x)
{
	for (int i = 1; i <= m; i++)
	{
		p[0][i] = 1;
		p[i][m + 1] = m;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = m; j > 0; j--)
		{
			t[x][i][j] = 1e9;
			for (int k = p[i - 1][j]; k <= p[i][j + 1]; k++)
			{
				if (t[x][i][j] > t[x * 2][i][k] + t[x * 2 + 1][k][j])
				{
					t[x][i][j] = t[x * 2][i][k] + t[x * 2 + 1][k][j];
					p[i][j] = k;
				}
			}
		}
	}
}
void build(int x, int l, int r)
{
	if (l == r)
	{
		init(x, max(l * b, 1), min((r + 1) * b - 1, n));
		return;
	}
	int m = (l + r) / 2;
	build(x * 2, l, m);
	build(x * 2 + 1, m + 1, r);
	merge(x);
}
void change(int x, int l, int r, int p)
{
	if (l == r)
	{
		init(x, max(l * b, 1), min((r + 1) * b - 1, n));
		return;
	}
	int m = (l + r) / 2;
	if (p > m)
	{
		change(x * 2 + 1, m + 1, r, p);
	}
	else
	{
		change(x * 2, l, m, p);
	}
	merge(x);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			scanf("%d", &h[i][j]);
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &v[i][j]);
		}
	}
	build(1, 0, n / b);
	scanf("%d", &e);
	for (int i = 0; i < e; i++)
	{
		int o, p, q, w, v1, v2;
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d%d%d", &p, &q, &w);
			h[++p][++q] = w;
			change(1, 0, n / b, p / b);
		}
		else if (o == 2)
		{
			scanf("%d%d%d", &p, &q, &w);
			v[++p][++q] = w;
			change(1, 0, n / b, p / b);
		}
		else if (o == 3)
		{
			scanf("%d%d", &v1, &v2);
			printf("%d\n", t[1][++v1][++v2]);
		}
	}
	return 0;
}