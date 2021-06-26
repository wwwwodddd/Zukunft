#include <bits/stdc++.h>
using namespace std;
void gao(int x, int y, int a, int b, int l)
{
	if (l == 0)
	{
		return;
	}
	if (x < l + a && y < l + b)
	{
		printf("%d %d 1\n", a + l, b + l);
		gao(x, y, a, b, l / 2);
	}
	else
	{
		gao(a + l - 1, b + l - 1, a, b, l / 2);
	}
	if (x < l + a && y >= l + b)
	{
		printf("%d %d 2\n", a + l, b + l - 1);
		gao(x, y, a, b + l, l / 2);
	}
	else
	{
		gao(a + l - 1, b + l, a, b + l, l / 2);
	}
	if (x >= l + a && y < l + b)
	{
		printf("%d %d 3\n", a + l - 1, b + l);
		gao(x, y, a + l, b, l / 2);
	}
	else
	{
		gao(a + l, b + l - 1, a + l, b, l / 2);
	}
	if (x >= l + a && y >= l + b)
	{
		printf("%d %d 4\n", a + l - 1, b + l - 1);
		gao(x, y, a + l, b + l, l / 2);
	}
	else
	{
		gao(a + l, b + l, a + l, b + l, l / 2);
	}
}
int main()
{
	int n, x, y;
	scanf("%d%d%d", &n, &x, &y);
	gao(x, y, 1, 1, 1 << (n - 1));
	return 0;
}