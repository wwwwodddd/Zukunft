#include <bits/stdc++.h>
using namespace std;
int n, m, q, x, y;
int f[400020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
bool U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x == y)
	{
		return false;
	}
	else
	{
		f[x] = y;
		return true;
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	int z = n + m - 1;
	for (int i = 1; i <= n + m; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &x, &y);
		if (U(x, y + n))
		{
			z--;
		}
	}
	printf("%d\n", z);
	return 0;
}