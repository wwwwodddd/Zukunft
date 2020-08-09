#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[4020];
int v[4020], l[4020];
bool dfs(int x)
{
	for (int i: a[x])
	{
		if (!v[i])
		{
			v[i] = true;
			if (l[i] == 0 || dfs(l[i]))
			{
				l[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
	{
		a[i].resize(4);
		scanf("%d%d", &a[i][0], &a[i][1]);
		a[i][2] = a[i][0] + n;
		a[i][3] = a[i][1] + n;
	}
	int z = 0;
	for (int i = 1; i <= 2 * n; i++)
	{
		memset(v, 0, sizeof v);
		if (dfs(i))
		{
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}