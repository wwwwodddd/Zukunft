#include <bits/stdc++.h>
using namespace std;
int t[500020][2], tt;
int s[500020];
int c[500020];
int n, m, l, x;
int a[10020];
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &l);
		int p = 0;
		for (int j = 0; j < l; j++)
		{
			scanf("%d", &x);
			if (t[p][x] == 0)
			{
				t[p][x] = ++tt;
			}
			p = t[p][x];
			s[p]++;
		}
		c[p]++;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &l);
		for (int j = 0; j < l; j++)
		{
			scanf("%d", &a[j]);
		}
		int p = 0, z = 0;
		for (int j = 0; j < l; j++)
		{
			z += c[p];
			if (t[p][a[j]] == 0)
			{
				p = 0;
				break;
			}
			p = t[p][a[j]];
		}
		printf("%d\n", z + s[p]);
	}
	return 0;
}