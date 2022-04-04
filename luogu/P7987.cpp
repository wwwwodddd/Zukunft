#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y;
vector<pair<int, int> > a;
int f[100020][2];
int g[100020][2];
int T(int x, int y)
{
	if (t == 1)
	{
		return min(x, y);
	}
	else
	{
		return max(x, y);
	}
}
inline int clr()
{
	if (t == 1)
	{
		return 1e9;
	}
	else
	{
		return -1e9;
	}
}
int zuo()
{
	for (int i = 0; i <= a.size(); i++)
	{
		f[i][0] = f[i][1] = g[i][0] = g[i][1] = clr();
	}
	f[0][0] = 0;
	g[0][0] = 0;
	int z = f[0][a.size() % 2];
	for (int i = 1, j = 0; i <= a.size(); i++)
	{
		while (a[i - 1].first > a[j].first + m)
		{
			j++;
		}
		// printf("i=%d j=%d\n", i, j);
		for (int k = 0; k < 2; k++)
		{
			if ((i + k) % 2 == 1 && (i == a.size() || a[i].first > a[i - 2].first + m))
			{
				// printf("CONTINUE i=%d k=%d\n", i, k);
			}
			else
			{
				f[i][k] = g[j][k ^ 1] + a[i - 1].second; // a[i] > a[j] + k;
			}
			g[i][k] = T(g[i - 1][k], f[i][k]);
		}
		z = T(z, f[i][a.size() % 2]);
	}
	// for (int i = 0; i <= a.size(); i++)
	// {
	// 	printf("%2d %12d %12d %12d %12d\n", i, f[i][0], f[i][1], g[i][0], g[i][1]);
	// }
	return z;
}
int main()
{
	int z = 0;
	scanf("%d%d%d", &t, &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		if (i > 0 && a.back().first + m < x)
		{
			z += zuo();
			a.clear();
		}
		a.push_back(make_pair(x, y));
	}
	z += zuo();
	printf("%d\n", z);
	return 0;
}