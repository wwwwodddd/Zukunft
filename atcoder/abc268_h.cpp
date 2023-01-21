#include <bits/stdc++.h>
using namespace std;
int n;
int t[500020][26], tt;
int f[500020];
int s[500020];
int v[500020];
int q[500020], qq;
char cc[500020];
char c[500020];
void ins(char *s)
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
	v[p] = 1;
}
int main()
{
	scanf("%s", cc);
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
		for (int i = 0; i < 26; i++)
		{
			if (t[u][i])
			{
				f[t[u][i]] = u ? t[f[u]][i] : 0;
				v[t[u][i]] |= v[f[t[u][i]]];
				q[qq++] = t[u][i];
			}
			else
			{
				t[u][i] = t[f[u]][i];
			}
		}
	}
	int z = 0;
	for (int p = 0, i = 0; cc[i]; i++)
	{
		p = t[p][cc[i] - 'a'];
		if (v[p])
		{
			p = 0;
			z++;
		}
	}
	printf("%d\n", z);
	return 0;
}