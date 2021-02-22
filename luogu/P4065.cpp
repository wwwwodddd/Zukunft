#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, x;
ll a[300020];
int l[300020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		memset(l, 0, sizeof l);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			if (l[x])
			{
				a[l[x]] ^= a[i] = (ll)rand() << 30 | rand();
			}
			l[x] = i;
		}
		ll s = 0, z = 0;
		map<ll, int> g;
		g[s]++;
		for (int i = 1; i <= n; i++)
		{
			z += g[s ^= a[i]]++;
		}
		printf("%lld\n", z);
	}
	return 0;
}