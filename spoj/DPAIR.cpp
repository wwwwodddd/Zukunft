#include <bits/stdc++.h>
using namespace std;
int n, x, q, l, r;
int a[1000020];
int v[1000020];
long long s[1000020];
int main()
{
	scanf("%d", &n);
	for (int i = 1, j = 0; i <= n; i++)
	{
		scanf("%d", &x);
		j = max(j, v[x]);
		s[i - j]++;
		v[x] = i;
	}
	for (int i = n; i > 1; i--)
	{
		s[i - 1] += s[i];
	}
	for (int i = 1; i <= n; i++)
	{
		s[i] += s[i - 1];
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &l, &r);
		printf("%lld\n", s[r] - s[l - 1]);
	}
	return 0;
}