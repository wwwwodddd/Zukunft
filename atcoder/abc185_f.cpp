#include <bits/stdc++.h>
using namespace std;
int n, q, o, x, y;
int c[300020];
void change(int x, int y)
{
	for(; x <= n; x += x & -x)
	{
		c[x] ^= y;
	}
}
int query(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re ^= c[x];
	}
	return re;
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &c[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (i + (i & -i) <= n)
		{
			c[i + (i & -i)] ^= c[i];
		}
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d%d", &o, &x, &y);
		if (o == 1)
		{
			change(x, y);
		}
		else
		{
			printf("%d\n", query(y) ^ query(x - 1));
		}
	}
	return 0;
}
