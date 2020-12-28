#include <bits/stdc++.h>
using namespace std;
vector<int> a[100020];
int n, x;
long long d[100020];
int c[100020];
long long z;
long long dfs(int x)
{
	long long s = 0;
	for (int i: a[x])
	{
		s += dfs(i);
		c[x] = min(c[x], c[i]);
	}
	z += max(d[x] - s, 0LL) * c[x];
	d[x] = max(d[x], s);
	return d[x];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%lld%d", &x, &d[i], &c[i]);
		if (x > 0)
		{
			a[x].push_back(i);
		}
	}
	dfs(1);
	printf("%lld\n", z);
	return 0;
}