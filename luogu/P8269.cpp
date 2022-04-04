#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[1000020], q[2000020], in[1000020], n, flg;
int c[1000020];
int v[1000020];
ll g[1000020][2];
ll f[1000020][2];
int w[1000020];
ll ans;
void dfs(int x)
{
	int i;
	flg++;
	for (i = x;; i = a[i])
	{
		if (v[i] == flg)
			break;
		if (v[i])
			return;
		v[i] = flg;
	}
	for (; !c[i]; i = a[i])
		c[i] = 1;
}
void cdp(int x)
{
	int i, ss = 0;
	for (i = x; c[i]; i = a[i])
		q[++ss] = i, c[i] = 0;
	int re = w[q[1]];
	for (i = 1; i <= ss; i++)
	{
		re = min(re, w[q[i]]);
	}
	ans -= re;
}
int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i], &w[i]), in[a[i]]++;
		ans += w[i];
	}
	for (i = 1; i <= n; i++)
		if (!v[i])
			dfs(i);
	for (i = 1; i <= n; i++)
		if (c[i])
			cdp(i);
	printf("%lld\n", ans);
	return 0;
}