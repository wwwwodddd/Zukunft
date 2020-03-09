#include <bits/stdc++.h>
using namespace std;
int n;
int t[200020][26], tt;
int f[200020];
int s[200020];
int a[200020];
int q[200020], qq;
char c[2000020];
int ins(char *s)
{
	int p = 0;
	for (; *s; s++)
	{
		if (t[p][*s - 'a'] == 0)
		{
			t[p][*s - 'a'] = ++tt;
		}
		p = t[p][*s - 'a'];
	}
	return p;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", c);
		a[i] = ins(c);
	}
	q[qq++] = 0;
	for (int j = 0; j < qq; j++)
	{
		int u = q[j];
		for (int i = 0; i < 26; i++)
		{
			if (t[u][i])
			{
				f[t[u][i]] = u ? t[f[u]][i] : 0;
				q[qq++] = t[u][i];
			}
			else
			{
				t[u][i] = t[f[u]][i];
			}
		}
	}
	scanf("%s", c);
	for (int p = 0, i = 0; c[i]; i++)
	{
		p = t[p][c[i] - 'a'];
		s[p]++;
	}
	for (int i = tt; i > 0; i--)
	{
		s[f[q[i]]] += s[q[i]];
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", s[a[i]]);
	}
	return 0;
}