#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		long long s = 0, mn = 0, mx = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			s += x;
			mn = min(mn, s);
			mx = max(mx, s);
		}
		printf("%lld\n", mx - mn);
	}
	return 0;
}