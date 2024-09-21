#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[500020];
int f[500020];
int mn, n, p;
long long s, z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].second, &a[i].first);
	}
	sort(a, a + n);
	f[n] = mn = 1 << 30;
	for (int i = n - 1; i >= 0; i--)
	{
		f[i] = min(f[i + 1], a[i].second);
	}
	for (int i = 0; i < n; i++)
	{
		z = s + f[i];
		s += a[i].first;
		mn = min(mn, a[i].second - a[i].first);
		printf("%lld\n", min(z, s + mn));
	}
	return 0;
}
