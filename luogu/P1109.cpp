#include <bits/stdc++.h>
using namespace std;
int n, a[50], s, l, r, x, y;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		s += a[i];
	}
	scanf("%d%d", &l, &r);
	for (int i = 0; i < n; i++)
	{
		x += max(l - a[i], 0);
		y += max(a[i] - r, 0);
	}
	if (s < l * n || s > r * n)
	{
		puts("-1");
	}
	else
	{
		printf("%d\n", max(x, y));
	}
	return 0;
}