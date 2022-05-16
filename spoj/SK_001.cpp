#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		map<int, int> g;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			g[x]++;
		}
		long long z = 0, c = 0;
		for (auto i: g)
		{
			z += i.second * ++c;
		}
		printf("%lld\n", z % 1000000007);
	}
	return 0;
}