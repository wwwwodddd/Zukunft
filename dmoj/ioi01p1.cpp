#include <bits/stdc++.h>
using namespace std;
int c[1030][1030];
int ans;
int n, x, y, u, v;
int i, j, o;
void R(int x, int y, int v)
{
	for (int i = x; i <= n; i += i & -i)
	{
		for (int j = y; j <= n; j += j & -j)
		{
			c[i][j] += v;
		}
	}
}
int G(int x, int y)
{
	int q = 0;
	for (int i = x; i > 0; i -= i & -i)
	{
		for (int j = y; j > 0; j -= j & -j)
		{
			q += c[i][j];
		}
	}
	return q;
}
int main()
{
	scanf("%d %d", &o, &n);
	while (1)
	{
		scanf("%d", &o);
		if (o == 1)
		{
			scanf("%d %d %d", &x, &y, &u);
			R(x + 1, y + 1, u);
		}
		else if (o == 2)
		{
			scanf("%d %d %d %d", &x, &y, &u, &v);
			u++, v++;
			printf("%d\n", G(x, y) + G(u, v) - G(x, v) - G(u, y));
		}
		else if (o == 3)
		{
			break;
		}
	}
	return 0;
}
