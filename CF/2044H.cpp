#include <bits/stdc++.h>
#define BUFSIZE 100000000
char buf[BUFSIZE], *pt = buf;
#define scan(t)                          \
	{                                    \
		t = 0;                           \
		while (*pt < '0' || *pt > '9')   \
			pt++;                        \
		while (*pt >= '0' && *pt <= '9') \
			t = t * 10 + (*pt++) - '0';  \
	}
using namespace std;
int t, n, q;
long long a[2020][2020];
long long s[2020][2020];
long long si[2020][2020];
long long sj[2020][2020];
int main()
{
	fread(buf, 1, BUFSIZE, stdin);
	scan(t);
	for (int tt = 0; tt < t; tt++)
	{
		scan(n);
		scan(q);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scan(a[i][j]);
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
				si[i][j] = si[i - 1][j] + si[i][j - 1] - si[i - 1][j - 1] + a[i][j] * i;
				sj[i][j] = sj[i - 1][j] + sj[i][j - 1] - sj[i - 1][j - 1] + a[i][j] * j;
			}
		}
		for (int i = 0; i < q; i++)
		{
			int x1, y1, x2, y2;
			scan(x1);
			scan(y1);
			scan(x2);
			scan(y2);
			x1--;
			y1--;
			long long v = s[x2][y2] - s[x2][y1] - s[x1][y2] + s[x1][y1];
			long long vi = si[x2][y2] - si[x2][y1] - si[x1][y2] + si[x1][y1];
			long long vj = sj[x2][y2] - sj[x2][y1] - sj[x1][y2] + sj[x1][y1];
			vj -= v * y1;
			vi -= v * (x1 + 1);
			printf("%lld ", vi * (y2 - y1) + vj);
		}
		printf("\n");
	}
	return 0;
}