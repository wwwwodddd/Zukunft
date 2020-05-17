#include <bits/stdc++.h>
using namespace std;
int n, z;
int h[100020];
int o[100020];
int c[100020];
void change(int x, int y)
{
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &h[i]);
		o[i] = i;
	}
	sort(o + 1, o + 1 + n, [](int x,int y){return h[x]>h[y];});
	for (int i = 1; i <= n; i++)
	{
		int l = query(o[i]);
		int r = i - 1 - l;
		if (max(l, r) > 2 * min(l, r))
		{
			z++;
		}
		change(o[i], 1);
	}
	printf("%d\n", z);
	return 0;
}