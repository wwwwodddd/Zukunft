#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<long long> a;
long long z;
int main()
{
	scanf("%d%d", &n, &m);
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for (int i = 59; i >= 0; i--)
	{
		long long s = 0;
		vector<long long> b;
		for (long long j : a)
		{
			s ^= j;
			if (~s >> i & 1)
			{
				b.push_back(s);
				s = 0;
			}
		}
		if (s == 0 && b.size() >= m)
		{
			a.swap(b);
		}
		else
		{
			z |= 1LL << i;
		}
	}
	printf("%lld\n", z);
	return 0;
}