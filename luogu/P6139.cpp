#include <bits/stdc++.h>
using namespace std;
int n, x, tt;
char s[2000020];
int t[2000020][26];
int f[2000020];
int l[2000020];
long long z;
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
	z += l[np] - l[f[np]];
}
int main()
{
	f[0] = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		p = 0;
		for (int j = 0; s[j]; j++)
		{
			ins(s[j] - 'a');
		}
	}
	printf("%lld\n", z);
	return 0;
}