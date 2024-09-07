#include <bits/stdc++.h>
using namespace std;
int n, x, tt;
string s[100020];
int t[200020][26];
int f[200020];
int l[200020];
int v[200020];
long long z[200020];
int p;
void ins(int c)
{
	int np = ++tt;
	l[np] = l[p] + 1;
	for(; p != -1 && !t[p][c]; p = f[p])
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
		if(l[p] + 1 == l[q])
		{
			f[np] = q;
		}
		else
		{
			++tt;
			l[tt] = l[p] + 1;
			memcpy(t[tt], t[q], sizeof t[q]);
			f[tt] = f[q];
			for(; p != -1 && t[p][c] == q; p = f[p])
			{
				t[p][c] = tt;
			}
			f[q] = f[np] = tt;
		}
	}
	p = np;
}
int main()
{
	f[0] = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		p = 0;
		for (int j = 0; j < s[i].size(); j++)
		{
			ins(s[i][j] - 'a');
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int p = 0;
		for (int j = 0; j < s[i].size(); j++)
		{
			p = t[p][s[i][j] - 'a'];
			for (int k = p; k > 0 && v[k] != -1 && v[k] != i; k = f[k])
			{
				if (v[k] == 0)
				{
					v[k] = i;
				}
				else
				{
					v[k] = -1;
				}
			}
		}
	}
	for (int i = 1; i <= tt; i++)
	{
		if (v[i] > 0)
		{
			z[v[i]] += l[i] - l[f[i]];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%lld\n", z[i]);
	}
	return 0;
}