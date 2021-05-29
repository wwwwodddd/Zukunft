#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[2049][2049];
int b[2049][2049];
int c[2049][2049];
int d[2049][2049];
void change(int x, int y, int z)
{
	for (int i = x; i <= n; i += i & -i)
	{
		for (int j = y; j <= m; j += j & -j)
		{
			a[i][j] += z;
			b[i][j] += z * x;
			c[i][j] += z * y;
			d[i][j] += z * x * y;
		}
	}
}
int query(int x, int y)
{
	int ra = 0, rb = 0, rc = 0, rd = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		for (int j = y; j > 0; j -= j & -j)
		{
			ra += a[i][j];
			rb += b[i][j];
			rc += c[i][j];
			rd += d[i][j];
		}
	}
	return ra * (x + 1) * (y + 1) - rb * (y + 1) - rc * (x + 1) + rd;
}
int main()
{
	scanf("X %d %d", &n, &m);
	for (char o; ~scanf(" %c", &o);)
	{
		int x1, y1, x2, y2, z;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (o == 'L')
		{
			scanf("%d", &z);
			change(x1, y1, z);
			change(x1, y2 + 1, -z);
			change(x2 + 1, y1, -z);
			change(x2 + 1, y2 + 1, z);
		}
		else
		{
			printf("%d\n", query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
		}
	}
	return 0;
}