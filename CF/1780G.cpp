#include <bits/stdc++.h>
using namespace std;
int n, tt;
char b[2000020];
int a[2000020];
int c[2000020];
long long s[2000020];
int t[2000020][26];
int f[2000020];
int l[2000020];
vector<int> d[1000020];
long long z;
void ins(int c)
{
	static int p = 0;
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
	s[np] = 1;
}
int main()
{
	f[0] = -1;
	scanf("%d%s", &n, b);
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
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j += i)
		{
			d[j].push_back(i);
		}
	}
	for (int i = tt; i > 0; i--)
	{
		s[f[a[i]]] += s[a[i]];
		z += s[a[i]] * (upper_bound(d[s[a[i]]].begin(), d[s[a[i]]].end(), l[a[i]]) - upper_bound(d[s[a[i]]].begin(), d[s[a[i]]].end(), l[f[a[i]]]));
	}
	printf("%lld\n", z);
	return 0;
}