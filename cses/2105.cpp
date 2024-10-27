#include <bits/stdc++.h>
using namespace std;
int n, x, tt;
char s[200020];
int t[200020][26];
int f[200020];
int l[200020];
long long z;
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
	z += l[np] - l[f[np]];
}
int main()
{
	f[0] = -1;
	scanf("%s", s);
	for (int i = 0; s[i]; i++)
	{
		ins(s[i] - 'a');
	}
	printf("%lld\n", z);
	return 0;
}