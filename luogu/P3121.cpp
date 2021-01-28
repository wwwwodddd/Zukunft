#include <bits/stdc++.h>
using namespace std;
int n, m;
int t[200020][26], tt;
int f[200020];
int s[200020];
int v[200020];
int a[200020];
int q[200020], qq;
char o[2000020];
char c[2000020];
void ins(char *s)
{
	int p = 0, l = strlen(s);
	for (; *s; s++)
	{
		if (t[p][*s - 'a'] == 0)
		{
			t[p][*s - 'a'] = ++tt;
		}
		p = t[p][*s - 'a'];
	}
	v[p] = l;
}
int main()
{
	scanf("%s", o);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", c);
		ins(c);
	}
	q[qq++] = 0;
	for (int j = 0; j < qq; j++)
	{
		int u = q[j];
		v[u] |= v[f[u]];
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
	for (int p = 0, i = 0; o[i]; i++)
	{
		p = t[p][o[i] - 'a'];
		o[m++] = o[i];
		if (v[p])
		{
			m -= v[p];
			p = a[m];
		}
		else
		{
			a[m] = p;
		}
	}
	o[m] = 0;
	printf("%s\n", o);
	return 0;
}