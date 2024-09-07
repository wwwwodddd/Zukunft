#include <bits/stdc++.h>
using namespace std;
int n, q, x, y;
int a[1000020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", a[y + 1] - a[x]);
	}
	return 0;
}