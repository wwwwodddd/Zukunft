#include <bits/stdc++.h>
using namespace std;
int t, n, q, x;
int a[100020];
long long s[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++)
		{
			s[i + 1] = s[i] + a[i];
		}
		printf("Case %d:\n", tt);
		for (int i = 0; i < q; i++)
		{
			scanf("%d", &x);
			int l = lower_bound(a, a + n, x) - a;
			int r = upper_bound(a, a + n, x) - a;
			printf("%lld %lld\n", s[l], s[n] - s[r]);
		}
	}
	return 0;
}