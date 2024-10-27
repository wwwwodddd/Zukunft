#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		map<int, int> g;
		long long z = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &x);
			z += g[x]++;
		}
		printf("%lld\n", z);
	}
	return 0;
}