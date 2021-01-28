#include <bits/stdc++.h>
using namespace std;
int n;
int t[200020][26], tt;
int f[200020];
int s[200020];
int a[200020];
int q[200020], qq;
char c[200][80];
char o[1000080];
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
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		tt = 0;
		memset(t, 0, sizeof t);
		memset(f, 0, sizeof f);
		memset(s, 0, sizeof s);
		for (int i = 0; i < n; i++)
		{
			scanf("%s", c[i]);
			a[i] = ins(c[i]);
		}
		qq = 0;
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
		scanf("%s", o);
		for (int p = 0, i = 0; o[i]; i++)
		{
			p = t[p][o[i] - 'a'];
			s[p]++;
		}
		for (int i = tt; i > 0; i--)
		{
			s[f[q[i]]] += s[q[i]];
		}
		int mx = 0, cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (mx < s[a[i]])
			{
				mx = s[a[i]];
				cnt = 1;
			}
			else if (mx == s[a[i]])
			{
				cnt++;
			}
		}
		printf("%d\n", mx);
		for (int i = 0; i < n; i++)
		{
			if (mx == s[a[i]])
			{
				printf("%s\n", c[i]);
			}
		}
	}
	return 0;
}