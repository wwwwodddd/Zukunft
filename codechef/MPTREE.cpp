#include <bits/stdc++.h>
using namespace std;
vector<int> a[200020];
int b[200020];
map<int, int> f[200020];
map<int, int> g[200020];
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 21, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
void dfs(int x, int y)
{
	f[x][b[x]] = 1;
	for (int i : a[x])
	{
		if (i != y)
		{
			dfs(i, x);
			for (auto j : f[i])
			{
				f[x][std::gcd(j.first, b[x])] += j.second;
			}
		}
	}
}
void dfs2(int x, int y)
{
	for (int i : a[x])
	{
		if (i != y)
		{
			g[i] = f[i];
			for (auto j : g[x])
			{
				g[i][std::gcd(j.first, b[i])] += j.second;
			}
			for (auto j : f[i])
			{
				g[i][std::gcd(j.first, b[x])] -= j.second;
			}
			dfs2(i, x);
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &b[i]);
			a[i].clear();
			f[i].clear();
			g[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1, 0);
		g[1] = f[1];
		dfs2(1, 0);
		for (int i = 1; i <= n; i++)
		{
			long long s = 0;
			for (auto j : g[i])
			{
				for (int k : p)
				{
					if (j.first % k != 0)
					{
						s += (long long)k * j.second;
						break;
					}
				}
				// cout << i << " " << j.first << " " << j.second << endl;
			}
			printf("%lld ", s);
		}
		printf("\n");
	}
	return 0;
}