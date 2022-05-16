#include <bits/stdc++.h>
using namespace std;
int t[1000020][26];
int c[1000020];
int d[10020];
char s[120];
int tt, a, b, k, n, m;
void ins(char *s)
{
	int l = strlen(s), p = 0;
	c[p] = min(c[p], l * b);
	for (int i = 0; i < l; i++)
	{
		if (t[p][s[i] - 'a'] == 0)
		{
			t[p][s[i] - 'a'] = ++tt;
			c[tt] = 1e9;
		}
		p = t[p][s[i] - 'a'];
		c[p] = min(c[p], (l - 1 - i) * b);
	}
}
int ask(char *s)
{
	int l = strlen(s), p = 0, z = c[0] + l * a;
	for (int i = 0; i < l; i++)
	{
		if (t[p][s[i] - 'a'])
		{
			p = t[p][s[i] - 'a'];
			z = min(z, c[p] + (l - 1 - i) * a);
		}
		else
		{
			break;
		}
	}
	return z;
}
int main()
{
	int cases;
	scanf("%d", &cases);
	for (int casei = 0; casei < cases; casei++)
	{
		scanf("%d%d%d%d%d", &a, &b, &k, &n, &m);
		memset(t, 0, sizeof t);
		tt = 0;
		c[0] = 1e9;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s);
			ins(s);
		}
		for (int i = 0; i < m; i++)
		{
			scanf("%s", s);
			d[i] = ask(s);
		}
		sort(d, d + m);
		int z = 0;
		for (int i = 0; i < k; i++)
		{
			z += d[i];
		}
		printf("%d\n", z);
	}
	return 0;
}