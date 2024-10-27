#include <bits/stdc++.h>
using namespace std;
int n, x, tt;
char b[2000020];
int a[2000020];
int c[2000020];
int s[2000020];
int t[2000020][26];
int f[2000020];
long long g[2000020];
int l[2000020];
long long k;
void ins(int c)
{
	static int p = 0;
	int np = ++tt;
	l[np] = l[p] + 1;
	for (; p != -1 && !t[p][c]; p = f[p])
	{
		t[p][c] = np;
	}
	if (p == -1)
	{
		f[np] = 0;
	}
	else
	{
		int q = t[p][c];
		if (l[p] + 1 == l[q])
		{
			f[np] = q;
		}
		else
		{
			++tt;
			l[tt] = l[p] + 1;
			memcpy(t[tt], t[q], sizeof t[q]);
			f[tt] = f[q];
			for (; p != -1 && t[p][c] == q; p = f[p])
			{
				t[p][c] = tt;
			}
			f[q] = f[np] = tt;
		}
	}
	p = np;
	s[np] = 1;
}
int main()
{
	f[0] = -1;
	scanf("%s%lld", b, &k);
	n = strlen(b);
	for (int i = 0; i < n; i++)
	{
		ins(b[i] - 'a');
	}
	for (int i = 1; i <= tt; i++)
	{
		c[l[i]]++;
	}
	for (int i = 1; i <= tt; i++)
	{
		c[i] += c[i - 1];
	}
	for (int i = 1; i <= tt; i++)
	{
		a[c[l[i]]--] = i;
	}
	for (int i = tt; i > 0; i--)
	{
		s[f[a[i]]] += s[a[i]];
	}
	s[0] = 0;
	for (int i = tt; i >= 0; i--)
	{
		g[a[i]] = s[a[i]];
		for (int j = 0; j < 26; j++)
		{
			if (t[a[i]][j])
			{
				g[a[i]] += g[t[a[i]][j]];
			}
		}
	}
	int p = 0;
	while (true)
	{
		if (k > s[p])
		{
			k -= s[p];
			for (int j = 0; j < 26; j++)
			{
				if (t[p][j])
				{
					if (k > g[t[p][j]])
					{
						k -= g[t[p][j]];
					}
					else
					{
						putchar('a' + j);
						p = t[p][j];
						break;
					}
				}
			}
		}
		else
		{
			break;
		}
	}
	puts("");
	return 0;
}