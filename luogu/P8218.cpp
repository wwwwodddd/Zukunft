#include <bits/stdc++.h>
using namespace std;
int n, m, l, r;
int a[100020];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", a[r] - a[l - 1]);
	}
	return 0;
}