#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int a[200020];
int b[200020];
int vva[400020], *va = vva + 200010;
int vvb[400020], *vb = vvb + 200010;
int vv[400020], *v = vv + 200010;
long long sa;
long long sb;
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		sa += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (-200000 <= sa - a[i] && sa - a[i] <= 200000)
		{
			va[sa - a[i]] = 1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
		sb += b[i];
	}
	for (int i = 0; i < m; i++)
	{
		if (-200000 <= sb - b[i] && sb - b[i] <= 200000)
		{
			vb[sb - b[i]] = 1;
		}
	}
	if (va[0] || vb[0])
	{
		v[0] = 1;
	}
	for (long long i = -200000; i <= 200000; i++)
	{
		if (i == 0)
		{
			continue;
		}
		for (long long j = -200000 / abs(i); j <= 200000 / abs(i); j++)
		{
			if (va[i] && vb[j])
			{
				v[i * j] = 1;
			}
		}
	}
	for (int i = 0; i < q; i++)
	{
		int x;
		scanf("%d", &x);
		puts(v[x] ? "YES" : "NO");
	}
	return 0;
}