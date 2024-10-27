#include <bits/stdc++.h>
using namespace std;
int n, x, tt;
char s[200020];
int t[200020][26];
int f[200020];
int l[200020];
int z[200020];
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
	z[l[f[np]]]++;
	z[l[np]]--;
}
int main()
{
	f[0] = -1;
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		ins(s[i] - 'a');
	}
	for (int i = 0; i < n; i++)
	{
		z[i + 1] += z[i];
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", z[i]);
	}
	return 0;
}
