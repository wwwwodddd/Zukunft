#include <bits/stdc++.h>
using namespace std;
int n;
int s[120];
int f[120];
int l[120];
int r[120];
void dfs(int x)
{
	if (x)
	{
		dfs(l[x]);
		s[x] += s[l[x]];
		f[x] += f[l[x]] + s[l[x]];
		dfs(r[x]);
		s[x] += s[r[x]];
		f[x] += f[r[x]] + s[r[x]];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &s[i], &l[i], &r[i]);
	}
	dfs(1);
	int z = f[1], x = 1;
	while (true)
	{
		if (s[l[x]] * 2 > s[1])
		{
			z += s[1] - 2 * s[l[x]];
			x = l[x];
		}
		else if (s[r[x]] * 2 > s[1])
		{
			z += s[1] - 2 * s[r[x]];
			x = r[x];
		}
		else
		{
			break;
		}
	}
	printf("%d\n", z);
	return 0;
}