#include <bits/stdc++.h>
using namespace std;
const int m = 20;
int t[1000020][2], tt = 1;
int c[1000020];
int n;
char s[1000020];
int a[1000020];
int f[1000020][m];
long long z;
void ins(char *s)
{
	int p = 1;
	for (; *s; s++)
	{
		if (t[p][*s - '0'] == 0)
		{
			t[p][*s - '0'] = ++tt;
			assert(tt < 1000020);
		}
		p = t[p][*s - '0'];
	}
	c[p]++;
}
int main()
{
	f[0][0] = f[0][2] = 1;
	for (int i = 3; i < m; i++)
	{
		f[0][i] = f[0][i - 1] * 2;
	}
	scanf("%d", &n);
	assert(n <= 100000);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		ins(s);
	}
	for (int x = tt; x > 0; x--)
	{
		for (int i = 1; i < m; i++)
		{
			f[x][i] = f[t[x][0]][i - 1] + f[t[x][1]][i - 1];
		}
		if (f[x][1] == 2)
		{
			f[x][0] = 1;
			f[x][1] = 0;
			f[x][2] = 1;
		}
		for (int i = 0; i < m && c[x] > 0; i++)
		{
			while (f[x][i] > 0 && c[x] > 0)
			{
				f[x][i]--;
				c[x]--;
				z += i;
			}
		}
	}
	printf("%lld\n", z);
	return 0;
}