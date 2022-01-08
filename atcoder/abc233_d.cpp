#include <bits/stdc++.h>
using namespace std;
int n, x;
long long k, s, z;
map<long long, int> g;
int main()
{
	scanf("%d%lld", &n, &k);
	g[0]++;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		s += x;
		z += g[s - k];
		g[s]++;
	}
	printf("%lld\n", z);
	return 0;
}
