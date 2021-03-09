#include <bits/stdc++.h>
using namespace std;
int c[2000020];
int l[2000020];
int p[2000020];
int h[2000020];
int a[2000020][2];
int z[2000020];
int x, n, m, u;
stack<int> s;
void R(int x, int y)
{
	for (u += y; x <= n; x += x & -x)
		c[x] += y;
}
int G(int x)
{
	int re = 0;
	for (; x; x -= x & -x)
		re += c[x];
	return re;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		while (s.size() > 0 && s.top() > x)
		{
			s.pop();
		}
		if (s.size() == 0 || s.top() != x)
		{
			s.push(x);
		}
		else
		{
			p[i] = l[x];
		}
		l[x] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a[i][1], &x);
		a[i][0] = h[x];
		h[x] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		R(i, 1);
		if (p[i])
		{
			R(p[i], -1);
		}
		for (int j = h[i]; j; j = a[j][0])
		{
			z[j] = u - G(a[j][1] - 1);
		}
	}
	for (int i = 1; i <= m; i++)
	{
		printf("%d\n", z[i]);
	}
	return 0;
}