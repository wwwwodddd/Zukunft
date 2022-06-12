#include <bits/stdc++.h>
using namespace std;
int t, n;
long long a[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		long long s = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &a[i]);
			s += a[i];
			a[i] *= n;
		}
		long long z = 0;
		map<long long, int> g;
		for (int i = 0; i < n; i++)
		{
			a[i] -= s;
			z += g[-a[i]];
			g[a[i]]++;
		}
		printf("%lld\n", z);
	}
	return 0;
}