#include <bits/stdc++.h>
using namespace std;
int n, m, x, tt;
char s[10000020];
int t[20000020][4];
int f[20000020];
int l[20000020];
int O(char c)
{
	if (c == 'N')
	{
		return 0;
	}
	else if (c == 'S')
	{
		return 1;
	}
	else if (c == 'W')
	{
		return 2;
	}
	else
	{
		return 3;
	}
}
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
}
int main()
{
	f[0] = -1;
	scanf("%d%d%s", &n, &m, s);
	for (int i = 0; i < n; i++)
	{
		ins(O(s[i]));
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%s", s);
		int p = 0, j = 0;
		for (; s[j] && t[p][O(s[j])]; j++)
		{
			p = t[p][O(s[j])];
		}
		printf("%d\n", j);
	}
	return 0;
}