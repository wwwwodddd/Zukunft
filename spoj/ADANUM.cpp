#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[200020];
int b[200020];
int c[200020];
int d[200020]; 
int l[200020];
int r[200020];
int o[200020];
long long z[200020], p;
bool cmp(int x, int y)
{
	return make_pair(l[x] / 500, r[x]) < make_pair(l[y] / 500, r[y]);
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[m++] = a[i];
	}
	sort(b, b + m);
	m = unique(b, b + m) - b;
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(b, b + m, a[i]) - b;
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &l[i], &r[i]);
		o[i] = i;
	}
	sort(o, o + q, cmp);
	int L = 2, R = 1;
	for (int i = 0; i < q; i++)
	{
		while (l[o[i]] < L)
		{
			p += ++d[++c[a[--L]]];
		}
		while (R < r[o[i]])
		{
			p += ++d[++c[a[++R]]];
		}
		while (L < l[o[i]])
		{
			p -= d[c[a[L++]]--]--;
		}
		while (r[o[i]] < R)
		{
			p -= d[c[a[R--]]--]--;
		}
		z[o[i]] = p;
	}
	for (int i = 0; i < q; i++)
	{
		printf("%lld\n", z[i]);
	}
	return 0;
}
