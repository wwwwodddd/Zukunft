#include <bits/stdc++.h>
using namespace std;
map<int, int> g;
int n, x;
long long z;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		map<int, int> f;
		for (pair<int, int> j: g)
		{
			f[__gcd(j.first, x)] += j.second;
		}
		f[x]++;
		g.swap(f);
		for (pair<int, int> j: g)
		{
			z += (long long)j.first * j.second;
		}
	}
	printf("%lld\n", z);
	return 0;
}