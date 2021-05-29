#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[1020][1020];
vector<int> a[1000020];
int cnt;
const int mod = 1000000007;
int f[1000020];
int c[1000020];
int v[1000020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x > y)
	{
		f[x] = y;
	}
	else
	{
		f[y] = x;
	}
}
int G(int x)
{
	int re = 1;
	for (int i : a[x])
	{
		re = (long long)re * G(i) % mod;
	}
	return (re + 1) % mod;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n * m; i++)
	{
		f[i] = i;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.' && s[i + 1][j] == '.')
			{
				U(i * m + j, (i + 1) * m + j);
			}
		}
		for (int j = 1; j < m; j++)
		{
			if (s[i][j - 1] == '.' && s[i][j] == '.')
			{
				U(i * m + j - 1, i * m + j);
			}
		}
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.')
			{
				if (F(i * m + j) == i * m + j)
				{
					c[i * m + j] = ++cnt;
				}
				else
				{
					c[i * m + j] = c[F(i * m + j)];
				}
			}
		}
		for (int j = 0; j < m; j++)
		{
			if (s[i][j] == '.' && s[i + 1][j] == '.')
			{
				a[c[i * m + j]].push_back(c[(i + 1) * m + j]);
				v[c[(i + 1) * m + j]] = 1;
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		sort(a[i].begin(), a[i].end());
		a[i].resize(unique(a[i].begin(), a[i].end()) - a[i].begin());
	}
	int ans = 1;
	for (int i = 1; i <= cnt; i++)
	{
		if (v[i] == 0)
		{
			ans = (long long)ans * G(i) % mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}