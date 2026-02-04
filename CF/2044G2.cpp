#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> a[200020];
int p[200020];
int v[200020];
int dfs(int x, int y)
{
	v[x] = 1;
	int re = 1;
	for (int i : a[x])
	{
		if (i != y)
		{
			re += dfs(i, x);
		}
	}
	return re;
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		int z = 0;
		for (int i = 1; i <= n; i++)
		{
			v[i] = 0;
			a[i].clear();
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &p[i]);
			a[p[i]].push_back(i);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!v[i])
			{
				int j = i;
				while (v[j] == 0)
				{
					v[j] = 1;
					j = p[j];
				}
				vector<int> o;
				while (v[j] == 1)
				{
					o.push_back(j);
					v[j] = 2;
					j = p[j];
				}
				for (int k : o)
				{
					for (int x : a[k])
					{
						if (v[x] != 2)
						{
							z = max(z, dfs(x, k));
						}
					}
				}
			}
		}
		printf("%d\n", z + 2);
	}
	return 0;
}