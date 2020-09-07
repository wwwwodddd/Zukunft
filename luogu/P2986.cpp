#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
int c[100020];
vector<pair<int, int> > a[100020];
long long f[100020];
void dfs(int x, int y)
{
	for (pair<int, int> i: a[x])
	{
		if (i.first != y)
		{
			dfs(i.first, x);
			f[x] += f[i.first] + (long long)i.second * c[i.first];
			c[x] += c[i.first];
		}
	}
}
void dfs2(int x, int y)
{
	for (pair<int, int> i: a[x])
	{
		if (i.first != y)
		{
			f[i.first] = f[x] + (long long)(c[1] - 2 * c[i.first]) * i.second;
			dfs2(i.first, x);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
	}
	dfs(1, 0);
	dfs2(1, 0);
	printf("%lld\n", *min_element(f + 1, f + n + 1));
	return 0;
}